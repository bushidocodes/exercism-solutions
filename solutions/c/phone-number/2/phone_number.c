#include "phone_number.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

enum { RESULT_MAX = 11 };

char *phone_number_clean(const char *input) {
	// 10 digits plus null terminator
	char *result = calloc(sizeof(char), RESULT_MAX);
	size_t result_size = 0;

	for (size_t i = 0; i < strlen(input); i++) {
		if (result_size == RESULT_MAX) break;
		if (isdigit(input[i])) {
			// Ignore leading country code
			if (result_size == 0 && input[i] == '1') continue;
			result[result_size++] = input[i];
		}
	}

	// Confirm expected length and leading exchange code digit
	if (result_size == 10 && result[0] > '0' && result[3] >= '2' &&
	    result[3] <= '9')
		result[result_size++] = '\0';
	else
		strncpy(result, "0000000000", RESULT_MAX);

	return result;
}