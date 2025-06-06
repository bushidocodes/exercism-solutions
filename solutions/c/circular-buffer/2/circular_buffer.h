#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef uint16_t buffer_value_t;

typedef struct {
	bool is_full;
	uint16_t start;
	uint16_t end;
	uint16_t capacity;
	buffer_value_t *data;
} circular_buffer_t;

circular_buffer_t *new_circular_buffer(size_t capacity);
void delete_buffer(circular_buffer_t *buffer);

typedef enum {
	CB_SUCCESS,
	CB_FAILURE,
} CB_RC;

void clear_buffer(circular_buffer_t *buffer);

CB_RC read(circular_buffer_t *buffer, buffer_value_t *read_value);
CB_RC write(circular_buffer_t *buffer, buffer_value_t write_value);
CB_RC overwrite(circular_buffer_t *buffer, buffer_value_t write_value);
