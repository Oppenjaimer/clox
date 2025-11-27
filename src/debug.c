#include <stdio.h>

#include "debug.h"
#include "value.h"

static int constant_instruction(const char *name, Chunk *chunk, size_t offset) {
    uint8_t constant = chunk->code[offset + 1];
    printf("%-16s %4d '", name, constant);
    value_print(chunk->constants.values[constant]);
    printf("'\n");

    return offset + 2;
}

static int simple_instruction(const char *name, size_t offset) {
    printf("%s\n", name);

    return offset + 1;
}

void chunk_disassemble(Chunk *chunk, const char *name) {
    printf("=== %s ===\n", name);

    size_t offset = 0;
    while (offset < chunk->count) {
        offset = instruction_disassemble(chunk, offset);
    }
}

size_t instruction_disassemble(Chunk *chunk, size_t offset) {
    printf("%04ld ", offset);

    uint8_t opcode = chunk->code[offset];
    switch (opcode) {
        case OP_CONSTANT:
            return constant_instruction("OP_CONSTANT", chunk, offset);

        case OP_RETURN:
            return simple_instruction("OP_RETURN", offset);
        
        default:
            printf("Unknown opcode %d\n", opcode);
            return offset + 1;
    }
}
