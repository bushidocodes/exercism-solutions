#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "pangram.h"

#define LETTER_OFFSET ((size_t)'A')
#define LETTER_COUNT_CAPACITY ((size_t)26)

bool is_pangram(const char *const sentence)
{
    if (sentence == NULL) return false;

    size_t letter_count[LETTER_COUNT_CAPACITY] = {0};

    for (size_t i = 0; i < strlen(sentence); i++) {
        if (isalpha(sentence[i])) letter_count[toupper(sentence[i]) - LETTER_OFFSET]++;
    }

    for (size_t i = 0; i < LETTER_COUNT_CAPACITY; i++) {
        if (letter_count[i] == 0) return false;
    }

    return true;
}