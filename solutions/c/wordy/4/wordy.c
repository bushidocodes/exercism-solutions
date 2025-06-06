#include "wordy.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum operation {
	CALC_ADD,
	CALC_DIVIDE,
	CALC_MULTIPLY,
	CALC_SUBTRACT,
	CALC_UNKNOWN,
	CALC_COUNT
};

static const char *CALC_ADD_TOK = "plus ";
static const char *CALC_DIVIDE_TOK = "divided by ";
static const char *CALC_MULTIPLY_TOK = "multiplied by ";
static const char *CALC_SUBTRACT_TOK = "minus ";

static int get_digit(char **cursor) {
	int res;

	bool is_negative = false;
	if (**cursor == '-') {
		is_negative = true;
		(*cursor)++;
	}

	sscanf(*cursor, "%d", &res);

	if (is_negative) res *= -1;

	while (isdigit(**cursor) || isspace(**cursor)) (*cursor)++;

	return res;
}

static enum operation get_operation(char **cursor) {
	const size_t CALC_ADD_TOK_LEN = strlen(CALC_ADD_TOK);
	const size_t CALC_DIVIDE_TOK_LEN = strlen(CALC_DIVIDE_TOK);
	const size_t CALC_MULTIPLY_TOK_LEN = strlen(CALC_MULTIPLY_TOK);
	const size_t CALC_SUBTRACT_TOK_LEN = strlen(CALC_SUBTRACT_TOK);

	while (!isalpha(**cursor)) (*cursor)++;

	if (strncmp(*cursor, CALC_ADD_TOK, CALC_ADD_TOK_LEN) == 0) {
		*cursor += CALC_ADD_TOK_LEN;
		return CALC_ADD;
	} else if (strncmp(*cursor, CALC_SUBTRACT_TOK, CALC_ADD_TOK_LEN) == 0) {
		*cursor += CALC_SUBTRACT_TOK_LEN;
		return CALC_SUBTRACT;
	} else if (strncmp(*cursor, CALC_MULTIPLY_TOK, CALC_MULTIPLY_TOK_LEN) ==
	           0) {
		*cursor += CALC_MULTIPLY_TOK_LEN;
		return CALC_MULTIPLY;
	} else if (strncmp(*cursor, CALC_DIVIDE_TOK, CALC_DIVIDE_TOK_LEN) == 0) {
		*cursor += CALC_DIVIDE_TOK_LEN;
		return CALC_DIVIDE;
	} else {
		// We have no clear way to recover, so don't advance cursor
		return CALC_UNKNOWN;
	}
}

bool answer(const char *question, int *result) {
	// Check for valid question starting with expected prefix
	if (strncmp(question, "What is ", strlen("What is ")) != 0) return false;

	char *cursor = (char *)question;
	cursor += strlen("What is ");

	// Set the result to the first Get the first digit
	while (isspace(*cursor)) cursor++;
	if (!isdigit(*cursor) && *cursor != '-') return false;
	int buffer = get_digit(&cursor);

	while (*cursor != '?' && *cursor != '\0') {
		enum operation op = get_operation(&cursor);
		if (op == CALC_UNKNOWN) return false;

		while (isspace(*cursor)) cursor++;
		if (!isdigit(*cursor) && *cursor != '-') return false;

		int num = get_digit(&cursor);

		switch (op) {
			case CALC_ADD:
				buffer += num;
				break;
			case CALC_DIVIDE:
				buffer /= num;
				break;
			case CALC_SUBTRACT:
				buffer -= num;
				break;
			case CALC_MULTIPLY:
				buffer *= num;
				break;
			case CALC_UNKNOWN:
			default:
				return false;
		}

		// Advance past whitespace so while conditional evaluates cleanly
		while (*cursor != '\0' && !isalpha(*cursor)) (cursor)++;
	}

	*result = buffer;
	return true;
}