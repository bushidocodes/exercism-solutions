#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef uint16_t buffer_value_t;

typedef struct _circular_buffer_t {
	bool is_full;
	uint16_t start;
	uint16_t end;
	uint16_t capacity;
	buffer_value_t data[];
} circular_buffer_t;

// Status codes used by read, write, and overwrite
typedef int16_t errno_t;
#define CB_SUCCESS (errno_t)0
#define CB_FAILURE (errno_t)1

circular_buffer_t* new_circular_buffer(size_t capacity);
void delete_buffer(circular_buffer_t *const buffer);
void clear_buffer(circular_buffer_t *const buffer);

errno_t read(circular_buffer_t *const buffer, buffer_value_t *const read_value);
errno_t write(circular_buffer_t *const buffer, buffer_value_t write_value);
errno_t overwrite(circular_buffer_t *const buffer, buffer_value_t write_value);
