#include "nth_prime.h"

#include <stdbool.h>

#define MAX_NTH 10001

uint32_t nth(uint32_t n) {
	// Using 1-based indices, so index 0 is unused
	static uint32_t primes[MAX_NTH + 1] = {0, 2};
	static uint32_t prime_count = 1;
	// Because I'm memoizing results, I have a static limit
	if (n == 0 || n > MAX_NTH) return 0;

	uint32_t biggest_prime = primes[prime_count];

	for (uint32_t candidate = biggest_prime + 1; prime_count < n; candidate++) {
		bool is_prime = true;

		// if divisible by a known prime, not a prime
		for (uint32_t j = 1; j <= prime_count; j++) {
			if (candidate % primes[j] == 0) {
				is_prime = false;
				break;
			}
		}

		if (is_prime) primes[++prime_count] = candidate;
	}

	return primes[n];
}