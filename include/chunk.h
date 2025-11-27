#ifndef CLOX_CHUNK_H
#define CLOX_CHUNK_H

#include "common.h"

/**
 * @brief Enumeration of all instruction opcodes.
 */
typedef enum {
    OP_RETURN,  /// Return from current function.
} Opcode;

/**
 * @brief Dynamic array to store bytecode sequences.
 */
typedef struct {
    size_t count;       /// Current number of elements.
    size_t capacity;    /// Maximum number of elements.
    uint8_t *code;      /// Actual bytecode sequence.
} Chunk;

/**
 * @brief Initialize bytecode chunk.
 * 
 * The chunk starts off completely empty.
 * 
 * @param chunk Chunk to initialize.
 */
void chunk_init(Chunk *chunk);

/**
 * @brief Free bytecode chunk.
 * @param chunk Chunk to free.
 */
void chunk_free(Chunk *chunk);

/**
 * @brief Append a byte to the end of a chunk.
 * 
 * If the chunk doesn't have enough capacity, it's resized before appending the byte.
 * 
 * @param chunk Chunk to modify.
 * @param byte Byte to append.
 */
void chunk_write(Chunk *chunk, uint8_t byte);

#endif