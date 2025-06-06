#include "series.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

slices_t slices(char *input_text, unsigned int substring_length) {
	size_t input_length = strlen(input_text);

	bool is_valid = substring_length > 0 && substring_length <= input_length;

	slices_t result = {
	    .substring_count = is_valid ? input_length - (substring_length - 1) : 0,
	    .substring = is_valid ? calloc(sizeof(char *), result.substring_count)
	                          : &input_text};

	if (result.substring == NULL) exit(EXIT_FAILURE);

	for (size_t i = 0; i < result.substring_count; i++) {
		// Pad for \n
		result.substring[i] = calloc(sizeof(char), substring_length + 1);
		if (result.substring[i] == NULL) exit(EXIT_FAILURE);
		strncpy(result.substring[i], &input_text[i], substring_length);
	}

	return result;
}