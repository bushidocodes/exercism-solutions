#include "all_your_base.h"

#include <math.h>

size_t rebase(int8_t digits[DIGITS_ARRAY_SIZE], int16_t input_base,
              int16_t output_base, size_t input_length) {
	// Validate input
	if (input_length < 1 || input_base <= 1 || output_base <= 1) goto ERR;

	// Calculate decimal sum
	uint32_t sum = 0;
	for (size_t i = 0; i < input_length; i++) {
		int value = digits[input_length - 1 - i];
		if (value < 0 || value >= input_base) goto ERR;
		sum += value * pow(input_base, i);
	}

	// Determine the most significant digit
	int most_significant_pos;
	for (most_significant_pos = 0;
	     pow(output_base, most_significant_pos + 1) < sum;
	     most_significant_pos++)
		;

	// Write the output in the desired base
	size_t output_size = most_significant_pos + 1;
	for (size_t i = 0; i < output_size; i++) {
		int divisor = pow(output_base, most_significant_pos - i);
		digits[i] = sum / divisor;
		sum -= digits[i] * divisor;
	}

	return output_size;

ERR:
	digits[0] = 0;
	return 0;
}