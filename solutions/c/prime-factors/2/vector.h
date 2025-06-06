#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	size_t capacity;
	size_t count;
	uint32_t *data;
} vector_t;

typedef struct {
	bool did_succeed;
	uint32_t data;
} result_t;

void vector_init(vector_t *vector, size_t initial_size);
void vector_add(vector_t *vector, uint32_t elem);
result_t vector_get_nth(vector_t *vector, size_t nth);
size_t vector_get_count(vector_t *vector);
result_t vector_get_last(vector_t *vector);
void vector_free(vector_t *vector);

void vector_init(vector_t *vector, size_t initial_size) {
	vector->capacity = initial_size;
	vector->count = 0;
	vector->data = (uint32_t *)calloc(initial_size, sizeof(uint32_t));
}

void vector_add(vector_t *vector, uint32_t elem) {
	if (vector->count == vector->capacity) {
		vector->capacity *= 2;
		vector->data = (uint32_t *)realloc(vector->data,
		                                   vector->capacity * sizeof(uint32_t));
	}

	vector->data[vector->count] = elem;
	vector->count++;
}

result_t vector_get_nth(vector_t *vector, size_t nth) {
	result_t result;
	if (nth < vector->count) {
		result.did_succeed = true;
		result.data = vector->data[nth];
		return result;
	} else {
		result.did_succeed = false;
		return result;
	}
}

size_t vector_get_count(vector_t *vector) { return vector->count; }

result_t vector_get_last(vector_t *vector) {
	result_t result;
	if (vector->count != 0) {
		result.did_succeed = true;
		result.data = vector->data[vector->count - 1];
		return result;
	} else {
		result.did_succeed = false;
		return result;
	}
}

void vector_free(vector_t *vector) {
	free(vector->data);
	vector->capacity = 0;
	vector->count = 0;
}