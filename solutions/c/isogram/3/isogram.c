#include <string.h>
#include <ctype.h>
#include <stdio.h>

#include "isogram.h"

#define LETTER_COUNT 26

bool is_isogram(const char phrase[]) {
    if (phrase == NULL) return false;

    int letter_totals[LETTER_COUNT] = {0};
    for (int i = 0; i < (int)strlen(phrase); i++) {
        if (isalpha(phrase[i])) {
            if (++letter_totals[toupper(phrase[i]) - 'A'] > 1)
                return false;
        }
    }

    return true;
}
