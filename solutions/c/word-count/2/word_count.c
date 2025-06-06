#include "word_count.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Strips leading and trailing single quotes, but leaves internal single quotes
// used as apostrophes
// Takes a pointer to a pointer to avoid pass by value and advance the cursor
// forward to trim leading single quotes
static void strip_non_apostrophes(char **word) {
	// Advance the pointer to trim leading single quote
	if (**word == '\'') (*word)++;

	// Overwrite trailing single quote with null terminator
	char *last = *word + strlen(*word) - 1;
	if (*last == '\'') *last = '\0';
}

// Reset words data structure
static void clear_words(word_count_word_t *words) {
	for (unsigned int i = 0; i < MAX_WORDS; i++) {
		strncpy(words[i].text, "", MAX_WORD_LENGTH);
		words[i].count = 0;
	}
}

int count_words(const char *input_text, word_count_word_t *words) {
	int unique_word_count = 0;
	clear_words(words);

	// Copy input text by value and make case insensitive
	char buffer[strlen(input_text) + 1];
	strcpy(buffer, input_text);
	for (char *c = buffer; *c != '\0'; c++) *c = tolower(*c);

	// Tokenize on whitespace and punctuation, other than single quotes,
	// which can potentially be apostrophes that need to be preserved
	for (char *s = buffer; (s = strtok(s, " ,\n:!&@$%^&.")) != NULL; s = NULL) {
		if (strlen(s) > MAX_WORD_LENGTH + 1) return -1;

		strip_non_apostrophes(&s);

		for (unsigned int i = 0; i < MAX_WORDS; i++) {
			if (strcmp(words[i].text, s) == 0) {
				words[i].count++;
				break;
			} else if (strcmp(words[i].text, "") == 0) {
				strncpy(words[i].text, s, MAX_WORD_LENGTH + 1);
				words[i].count = 1;
				unique_word_count = i + 1;
				break;
			}

			if (i == MAX_WORDS - 1) return -2;
		}
	}

	return unique_word_count;
}