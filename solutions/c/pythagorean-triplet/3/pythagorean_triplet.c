#include "pythagorean_triplet.h"

#include <math.h>
#include <stdlib.h>

triplets_t *triplets_with_sum(uint16_t sum) {
	triplets_t *results = malloc(sizeof(triplets_t));
	results->count = 0;
	results->triplets = NULL;

	// The largest possible c is the floor of sum/2
	int largest_possible_c = sum / 2;

	int smallest_feasible_a = 3;
	int smallest_feasible_b = 4;
	int smallest_feasible_c = 5;

	for (int c = largest_possible_c; c >= smallest_feasible_c; c--) {
		// This can likely be further improved by deriving a better formula...
		for (int b = sqrt(c * c - smallest_feasible_a * smallest_feasible_a);
		     b < c && b >= smallest_feasible_b; b--) {
			if (b != (float)(int)b) continue;

			int b_sq = b * b;
			int a_sq = c * c - b_sq;
			if (a_sq >= b_sq) continue;

			float a = sqrt(a_sq);
			// If a perfect square and a proper sum
			if (a == (float)(int)a && a + b + c == sum) {
				results->count++;
				results->triplets = realloc(results->triplets,
				                            sizeof(triplet_t) * results->count);
				results->triplets[results->count - 1] =
				    (triplet_t){.a = a, .b = b, .c = c};
			}
		}
	}

	return results;
}

void free_triplets(triplets_t *t) {
	if (t == NULL) return;
	if (t->count > 0 && t != NULL) free(t->triplets);
	free(t);
}