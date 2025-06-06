#pragma once

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Note: I was using this earlier, but I refactored it out, so NOT USED IN
// ALGORITHM
const uint32_t VECTOR_BITS_PER_WORD = (sizeof(uint32_t) * 8);

typedef struct bitmap {
	uint32_t word_count;
	uint32_t *data;
} bitmap_t;

void bitmap_free(bitmap_t *bitmap);
bool bitmap_get(bitmap_t *bitmap, uint32_t n);
void bitmap_init(bitmap_t *bitmap, size_t initial_size);
bool bitmap_set(bitmap_t *bitmap, uint32_t n, bool state);

void bitmap_init(bitmap_t *bitmap, size_t initial_size_in_bits) {
	bitmap->word_count = initial_size_in_bits / VECTOR_BITS_PER_WORD;
	if (initial_size_in_bits % VECTOR_BITS_PER_WORD) bitmap->word_count++;
	assert(bitmap->word_count >= 1);
	bitmap->data = (uint32_t *)calloc(bitmap->word_count, sizeof(uint32_t));
}

void bitmap_free(bitmap_t *bitmap) { free(bitmap->data); }

bool bitmap_get(bitmap_t *bitmap, uint32_t n) {
	uint32_t word_idx = n / VECTOR_BITS_PER_WORD;
	uint32_t bit_idx = n % VECTOR_BITS_PER_WORD;

	// Just crash the program for now
	if (word_idx >= bitmap->word_count) exit(EXIT_FAILURE);

	uint32_t word = bitmap->data[word_idx];
	return ((1 << bit_idx) & word) > 0;
}

bool bitmap_set(bitmap_t *bitmap, uint32_t n, bool state) {
	uint32_t word_idx = n / VECTOR_BITS_PER_WORD;
	uint32_t bit_idx = n % VECTOR_BITS_PER_WORD;

	// Just crash the program for now
	if (word_idx > bitmap->word_count) exit(EXIT_FAILURE);

	if (state)
		bitmap->data[word_idx] |= (1 << bit_idx);
	else
		bitmap->data[word_idx] &= ~(1 << bit_idx);

	return ((1 << bit_idx) & bitmap->data[word_idx]) > 0;
}