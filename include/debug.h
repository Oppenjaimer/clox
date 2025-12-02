#ifndef CLOX_DEBUG_H
#define CLOX_DEBUG_H

#include "chunk.h"

/**
 * @brief Disassemble the instruction at a given offset within a chunk.
 * @param chunk Chunk containing the instruction.
 * @param offset Offset of the current instruction within the chunk.
 * @param previous_offset Offset of the previous instruction within the chunk.
 * @return Offset of the next instruction.
 */
size_t instruction_disassemble(Chunk *chunk, size_t offset, size_t previous_offset);

/**
 * @brief Disassemble all instructions in a chunk.
 * @param chunk Chunk whose instructions to disassemble.
 * @param name Name of the chunk.
 */
void chunk_disassemble(Chunk *chunk, const char *name);

#endif