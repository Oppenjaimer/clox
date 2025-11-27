#ifndef CLOX_MEMORY_H
#define CLOX_MEMORY_H

#include "common.h"

/**
 * @brief Double a given capacity.
 * 
 * The minimum capacity is 8. Any value less than that returns 8 instead of being doubled.
 * 
 * @param capacity Capacity to double.
 */
#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

/**
 * @brief Increase the capacity of a dynamic array.
 * 
 * This is a wrapper around `reallocate`.
 * 
 * @param type Data type of the array elements.
 * @param pointer Pointer to the array being grown.
 * @param old_capacity Old array capacity.
 * @param new_capacity New array capacity.
 */
#define GROW_ARRAY(type, pointer, old_capacity, new_capacity) \
    (type *)reallocate(pointer, sizeof(type) * (old_capacity), sizeof(type) * (new_capacity))

/**
 * @brief Free dynamic array.
 * 
 * This is a wrapper around `reallocate`.
 * 
 * @param type Data type of the array elements.
 * @param pointer Pointer to the array being freed.
 * @param old_capacity Old array capacity.
 */
#define FREE_ARRAY(type, pointer, old_capacity) \
    reallocate(pointer, sizeof(type) * (old_capacity), 0)

/**
 * @brief Reallocate dynamic memory.
 * 
 * Exits with status code 1 if reallocation fails.
 * 
 * @param pointer Pointer to the memory being reallocated.
 * @param old_size Old allocated size.
 * @param new_size New allocated size.
 * @return Pointer to the reallocated memory, or `NULL` if the memory was freed.
 */
void *reallocate(void *pointer, size_t old_size, size_t new_size);

#endif