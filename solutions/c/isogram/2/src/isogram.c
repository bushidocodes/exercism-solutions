#include <string.h>
#include <ctype.h>
#include <stdio.h>

#include "isogram.h"

#define LETTER_COUNT 26
#define CHAR_OFFSET 65

bool is_isogram(const char phrase[])
{
    if (phrase == NULL)
        return false;

    int string_length;
    if ((string_length = strlen(phrase)) == 0)
        return true;

    char buffer[string_length + 1];
    strcpy(buffer, phrase);
    for (int i = 0; i < string_length; i++)
        buffer[i] = toupper(phrase[i]);

    int letter_totals[LETTER_COUNT] = {0};

    for (int i = 0; i < string_length; i++)
        if (buffer[i] >= 'A' && buffer[i] <= 'Z' && ++letter_totals[buffer[i] - CHAR_OFFSET] > 1)
            return false;

    return true;
}
