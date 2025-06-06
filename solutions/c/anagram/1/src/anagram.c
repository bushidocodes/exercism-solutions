#include "anagram.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

enum
{
    LETTER_COUNT = 26
};

void anagrams_for(const char *word, struct candidates *candidates)
{
    // Determine the frequency of chars in original word (ignoring case)
    uint8_t word_letters[LETTER_COUNT] = {0};
    for (size_t i = 0; i < strlen(word) && i < MAX_STR_LEN; i++)
        if (isalpha(word[i]))
            word_letters[toupper(word[i]) - 'A']++;

    uint8_t candidate_letters[LETTER_COUNT] = {0};
    for (size_t i = 0; i < candidates->count; i++)
    {
        // Determine the frequency of chars in candidate (ignoring case)
        memset(&candidate_letters, 0, LETTER_COUNT * sizeof(int8_t));
        struct candidate *candidate = &candidates->candidate[i];
        for (size_t j = 0; j < strlen(candidate->candidate) && j < MAX_STR_LEN; j++)
            if (isalpha(candidate->candidate[j]))
                candidate_letters[toupper(candidate->candidate[j]) - 'A']++;

        // Check that original word and candidate have the same frequency of chars
        candidate->is_anagram = IS_ANAGRAM;
        for (size_t j = 0; j < LETTER_COUNT; j++)
            if (word_letters[j] != candidate_letters[j])
                candidate->is_anagram = NOT_ANAGRAM;

        // Check matching candidates to ensure its not the same word
        if (candidate->is_anagram)
        {
            bool is_same_word = true;
            for (size_t j = 0; j < strlen(candidate->candidate) && j < MAX_STR_LEN; j++)
                if (toupper(word[j]) != toupper(candidate->candidate[j]))
                    is_same_word = false;
            if (is_same_word)
                candidate->is_anagram = NOT_ANAGRAM;
        }
    }
}