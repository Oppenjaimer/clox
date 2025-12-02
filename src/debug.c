#include <stdio.h>

#include "debug.h"
#include "value.h"

static int constant_instruction(const char *name, Chunk *chunk, size_t offset) {
    uint8_t opcode = chunk->code[offset];
    size_t index = chunk->code[offset + 1];

    if (opcode == OP_CONSTANT_LONG) {
        index = (chunk->code[offset + 1] << 16)
                | (chunk->code[offset + 2] << 8)
                | (chunk->code[offset + 3] << 0);
    }

    printf("%-16s %4ld '", name, index);
    value_print(chunk->constants.values[index]);
    printf("'\n");

    return offset + (opcode == OP_CONSTANT_LONG ? 4 : 2);
}

static int simple_instruction(const char *name, size_t offset) {
    printf("%s\n", name);

    return offset + 1;
}

size_t instruction_disassemble(Chunk *chunk, size_t offset, size_t previous_offset) {
    printf("%04ld ", offset);

    int line = chunk_get_line(chunk, offset);
    if (offset > 0 && line == chunk_get_line(chunk, previous_offset)) {
        printf("   | ");
    } else {
        printf("%4d ", line);
    }

    uint8_t opcode = chunk->code[offset];
    switch (opcode) {
        case OP_CONSTANT:
            return constant_instruction("OP_CONSTANT", chunk, offset);

        case OP_CONSTANT_LONG:
            return constant_instruction("OP_CONSTANT_LONG", chunk, offset);

        case OP_RETURN:
            return simple_instruction("OP_RETURN", offset);

        default:
            printf("Unknown opcode %d\n", opcode);
            return offset + 1;
    }
}

void chunk_disassemble(Chunk *chunk, const char *name) {
    printf("=== %s ===\n", name);

    size_t offset = 0;
    size_t previous_offset = 0;

    while (offset < chunk->count) {
        size_t new_offset = instruction_disassemble(chunk, offset, previous_offset);
        previous_offset = offset;
        offset = new_offset;
    }
}
