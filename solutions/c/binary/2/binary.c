#include "binary.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

int convert(const char *input) {
	// Because size_t is often unsigned, i >= 0 is always true
	// Instead check for 0 at end of loop body
	uint64_t sum = 0;
	size_t last_digit_pos = strlen(input) - 1;

	// Because I am accumulating into uint64, the last index cannot exceed 63
	if (last_digit_pos > 63) return -1;
	for (size_t i = last_digit_pos; /* in body */; i--) {
		char c = input[i];
		if (c == '1')
			sum |= 1 << (last_digit_pos - i);
		else if (c != '0')
			return -1;

		if (i == 0) break;
	}
	return sum;
}