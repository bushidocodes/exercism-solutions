#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "pangram.h"
#define BASE_ALPHA 65

bool is_pangram(const char *sentence)
{
    if (sentence == NULL)
        return false;

    int letter_count[26] = {0};

    for (unsigned int i = 0; i < strlen(sentence); i++)
    {
        if (!isalpha(sentence[i]))
            continue;

        letter_count[toupper(sentence[i]) - BASE_ALPHA]++;
    }

    for (unsigned int i = 0; i < 26; i++)
    {
        if (letter_count[i] < 1)
            return false;
    }

    return true;
}