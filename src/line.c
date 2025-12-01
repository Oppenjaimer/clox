#include "line.h"
#include "memory.h"

void line_array_init(LineArray *array) {
    array->count = 0;
    array->capacity = 0;
    array->lines = NULL;
}

void line_array_free(LineArray *array) {
    FREE_ARRAY(Line, array->lines, array->capacity);
    line_array_init(array);
}

void line_array_write(LineArray *array, int line) {
    if (array->capacity < array->count + 1) {
        size_t old_capacity = array->capacity;
        array->capacity = GROW_CAPACITY(old_capacity);
        array->lines = GROW_ARRAY(Line, array->lines, old_capacity, array->capacity);
    }

    if (array->count > 0 && array->lines[array->count - 1].line == line)
        array->lines[array->count - 1].count++;
    else
        array->lines[array->count++] = (Line){ .count = 1, .line = line };
}