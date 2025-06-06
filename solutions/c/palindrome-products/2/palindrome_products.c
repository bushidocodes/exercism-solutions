#include "palindrome_products.h"

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline bool is_palindrome_product(int input) {
	const size_t BUFFER_SIZE = 100;
	char buffer[BUFFER_SIZE];
	snprintf((char *restrict)(&buffer), 100, "%d", input);
	size_t lo = 0;
	size_t hi = strlen(buffer) - 1;
	bool result = true;

	while (lo <= hi) {
		if (buffer[lo] != buffer[hi]) {
			result = false;
			break;
		}
		// size_t is unsigned, so protect against underflow
		if (hi == 0) break;
		hi--;
		lo++;
	}
	return result;
}

static inline void free_factors(factor_t *f) {
	if (f == NULL) return;
	factor_t *current = f;
	while (current != NULL) {
		factor_t *to_free = current;
		current = current->next;
		free(to_free);
	}
}

static inline product_t *alloc_product() {
	product_t *product = malloc(sizeof(product_t));
	product->largest = INT_MIN;
	product->smallest = INT_MAX;
	product->factors_lg = NULL;
	product->factors_sm = NULL;
	return product;
}
static inline factor_t *alloc_factor(int factor_a, int factor_b) {
	factor_t *factor = malloc(sizeof(factor_t));
	factor->factor_a = factor_a;
	factor->factor_b = factor_b;
	factor->next = NULL;
	return factor;
}

product_t *get_palindrome_product(int from, int to) {
	product_t *results = alloc_product();

	// Set Error message input is invalid
	if (from > to) {
		snprintf((char *restrict)(&results->error), MAXERR,
		         "invalid input: min is %d and max is %d", from, to);
		return results;
	}

	for (int i = from; i <= to; i++) {
		for (int j = i; j <= to; j++) {
			int product = i * j;
			if (product < results->smallest && is_palindrome_product(product)) {
				results->smallest = product;
				if (results->factors_sm != NULL)
					free_factors(results->factors_sm);

				results->factors_sm = alloc_factor(i, j);
			} else if (product == results->smallest) {
				assert(results->factors_sm != NULL);
				// Add to end of linked list
				factor_t *end = results->factors_sm;
				while (end->next != NULL) end = end->next;
				end->next = alloc_factor(i, j);
			}

			if (product > results->largest && is_palindrome_product(product)) {
				results->largest = product;
				if (results->factors_lg != NULL)
					free_factors(results->factors_lg);

				results->factors_lg = alloc_factor(i, j);
			} else if (product == results->largest) {
				assert(results->factors_lg != NULL);
				// Add to end of linked list
				factor_t *end = results->factors_lg;
				while (end->next != NULL) end = end->next;
				end->next = alloc_factor(i, j);
			}
		}
	}

	// Set Error message if none found
	if (results->largest == INT_MIN)
		snprintf((char *restrict)(&results->error), MAXERR,
		         "no palindrome with factors in the range %d to %d", from, to);

	return results;
}

void free_product(product_t *p) {
	free_factors(p->factors_lg);
	free_factors(p->factors_sm);
	free(p);
}