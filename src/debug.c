#include <stdio.h>

#include "debug.h"

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
        case OP_RETURN:
            return simple_instruction("OP_RETURN", offset);
        
        default:
            printf("Unknown opcode %d\n", opcode);
            return offset + 1;
    }
}
