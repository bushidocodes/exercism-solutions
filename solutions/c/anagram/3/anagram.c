#include "anagram.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

enum { LETTER_COUNT = 26 };

void find_anagrams(const char *subject, struct candidates *candidates) {
	// Determine the frequency of chars in original subject (ignoring case)
	uint8_t subject_letters[LETTER_COUNT] = {0};
	for (size_t i = 0; i < strlen(subject) && i < MAX_STR_LEN; i++)
		if (isalpha(subject[i])) subject_letters[toupper(subject[i]) - 'A']++;

	uint8_t candidate_letters[LETTER_COUNT] = {0};
	for (size_t i = 0; i < candidates->count; i++) {
		// Determine the frequency of chars in candidate (ignoring case)
		memset(&candidate_letters, 0, LETTER_COUNT * sizeof(int8_t));
		struct candidate *candidate = &candidates->candidate[i];
		for (size_t j = 0; j < strlen(candidate->word) && j < MAX_STR_LEN; j++)
			if (isalpha(candidate->word[j]))
				candidate_letters[toupper(candidate->word[j]) - 'A']++;

		// Check that original subject and candidate have the same frequency of
		// chars
		candidate->is_anagram = IS_ANAGRAM;
		for (size_t j = 0; j < LETTER_COUNT; j++)
			if (subject_letters[j] != candidate_letters[j])
				candidate->is_anagram = NOT_ANAGRAM;

		// Check matching candidates to ensure its not the same subject
		if (candidate->is_anagram) {
			bool is_same_subject = true;
			for (size_t j = 0; j < strlen(candidate->word) && j < MAX_STR_LEN;
			     j++)
				if (toupper(subject[j]) != toupper(candidate->word[j]))
					is_same_subject = false;
			if (is_same_subject) candidate->is_anagram = NOT_ANAGRAM;
		}
	}
}