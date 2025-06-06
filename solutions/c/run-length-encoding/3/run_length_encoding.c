#include "run_length_encoding.h"

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline void append (char* result, char c, int count) {
    char buffer[12] = {0};
    if (count > 1)
        sprintf(buffer, "%d%c", count, c);
    else
        sprintf(buffer, "%c", c);

    strcat(result, buffer);    
}

char* encode(const char *const text) {
	char* result = calloc(strlen(text) + 1, sizeof(char));
	int count = 0;
	char last = '\0';
	for (size_t i = 0; i < strlen(text); i++) {
        if (text[i] != last) {
            if (count > 0) append(result, last, count);
            last = text[i];
			count = 1;
        } else {
            count++;
        }
	}

    if (count > 0) append(result, last, count);

	return result;
}

const size_t RESULT_CAPACITY = 1000;

char* decode(const char *const data) {
	char* result = calloc(RESULT_CAPACITY, sizeof(char));
	size_t result_length = 0;
	for (size_t i = 0; i < strlen(data) && result_length < RESULT_CAPACITY; i++) {
		int counter = 1;
		if (isdigit(data[i])) {
			// Capture the digit and advance to a nondigit
			sscanf(&data[i], "%d", &counter);
			while (isdigit(data[i])) i++;
		}

		for (int j = 0; j < counter && result_length < RESULT_CAPACITY; j++) {   
            result[result_length++] = data[i];
        }
	};

	return result;
}