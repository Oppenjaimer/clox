#ifndef CLOX_LINE_H
#define CLOX_LINE_H

#include "common.h"

/**
 * @brief Run-length-encoded line.
 */
typedef struct {
    size_t count;   /// Number of occurrences.
    int line;       /// Line number.
} Line;

/**
 * @brief Dynamic array to store run-length-encoded line information.
 */
typedef struct {
    size_t count;       /// Current number of elements.
    size_t capacity;    /// Maximum number of elements.
    Line *lines;         /// Actual array of lines.
} LineArray;

/**
 * @brief Initialize line array.
 * 
 * The array starts off completely empty.
 * 
 * @param array Array to initialize.
 */
void line_array_init(LineArray *array);

/**
 * @brief Free line array.
 * @param array Array to free.
 */
void line_array_free(LineArray *array);

/**
 * @brief Append a line to the end of a line array.
 * 
 * If the array doesn't have enough capacity, it's resized before appending the line.
 * 
 * @param array Array to modify.
 * @param line Line to append.
 */
void line_array_write(LineArray *array, int line);

#endif