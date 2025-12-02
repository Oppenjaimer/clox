#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void chunk_init(Chunk *chunk) {
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
    
    line_array_init(&chunk->lines);
    value_array_init(&chunk->constants);
}

void chunk_free(Chunk *chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    line_array_free(&chunk->lines);
    value_array_free(&chunk->constants);
    chunk_init(chunk);
}

void chunk_write(Chunk *chunk, uint8_t byte, int line) {
    if (chunk->capacity < chunk->count + 1) {
        size_t old_capacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(old_capacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, old_capacity, chunk->capacity);
    }

    chunk->code[chunk->count++] = byte;
    line_array_write(&chunk->lines, line);
}

void chunk_write_constant(Chunk *chunk, Value value, int line) {
    value_array_write(&chunk->constants, value);
    size_t index = chunk->constants.count - 1;

    if (index <= UINT8_MAX) {
        chunk_write(chunk, OP_CONSTANT, line);
        chunk_write(chunk, index, line);
    } else {
        chunk_write(chunk, OP_CONSTANT_LONG, line);
        chunk_write(chunk, (index >> 16) & UINT8_MAX, line);
        chunk_write(chunk, (index >>  8) & UINT8_MAX, line);
        chunk_write(chunk, (index >>  0) & UINT8_MAX, line);
    }
}

int chunk_get_line(Chunk *chunk, size_t index) {
    size_t running_index = 0;

    for (size_t i = 0; i < chunk->lines.count; i++) {
        running_index += chunk->lines.lines[i].count;
        if (running_index > index) return chunk->lines.lines[i].line;
    }

    return -1;
}