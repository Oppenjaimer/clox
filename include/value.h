#ifndef CLOX_VALUE_H
#define CLOX_VALUE_H

#include "common.h"

typedef double Value;

/**
 * @brief Print a value to stdout.
 * @param value Value to print.
 */
void value_print(Value value);

/**
 * @brief Dynamic array to store values.
 */
typedef struct {
    size_t count;       /// Current number of values.
    size_t capacity;    /// Maximum number of values.
    Value *values;      /// Actual array of values.
} ValueArray;

/**
 * @brief Initialize value array.
 * 
 * The array starts off completely empty.
 * 
 * @param array Array to initialize.
 */
void value_array_init(ValueArray *array);

/**
 * @brief Free value array.
 * @param array Array to free.
 */
void value_array_free(ValueArray *array);

/**
 * @brief Append a value to the end of a value array.
 * 
 * If the array doesn't have enough capacity, it's resized before appending the value.
 * 
 * @param array Array to modify.
 * @param value Value to append.
 */
void value_array_write(ValueArray *array, Value value);

#endif