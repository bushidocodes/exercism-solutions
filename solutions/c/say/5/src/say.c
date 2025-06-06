#include "say.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

const char *base_words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

// Not using first two indices because 0-19 use special words
const char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

const size_t MAX_STR_LENGTH = 1000;

// Handles the special numbers between 0 - 999
static inline int say_to_999(const int64_t input, char **ans)
{
    int64_t buffer = input;
    if (input > 999 || *ans == NULL)
        return -1;

    if (buffer >= 100)
    {
        int64_t hundreds_value = buffer / 100;
        strncat(*ans, base_words[hundreds_value], MAX_STR_LENGTH - strlen(*ans) - 1);
        strncat(*ans, " hundred", MAX_STR_LENGTH - strlen(*ans) - 1);
        buffer -= (hundreds_value * 100);
        if (buffer > 0)
            strncat(*ans, " ", MAX_STR_LENGTH - strlen(*ans) - 1);
    }

    if (buffer >= 20)
    {
        int64_t tens_value = buffer / 10;
        strncat(*ans, tens[tens_value], MAX_STR_LENGTH - strlen(*ans) - 1);
        buffer -= (tens_value * 10);
        if (buffer > 0)
            strncat(*ans, "-", MAX_STR_LENGTH - strlen(*ans) - 1);
    }

    if (buffer > 0 && buffer < 20)
    {
        strncat(*ans, base_words[buffer], MAX_STR_LENGTH - strlen(*ans) - 1);
        buffer = 0;
    }
    return 0;
}

// Builds the string partial expressing 0-999 of {thousand, million, billion}
// f("",967000000000, 1000000000, "billion") => "nine hundred eighty-seven billion"
static inline void stringify_partial(int64_t *buffer, char **ans, int64_t partial_value, const char *partial_label)
{
    int64_t value = *buffer / partial_value;
    *buffer -= (value * partial_value);
    say_to_999(value, ans);
    strncat(*ans, " ", MAX_STR_LENGTH - strlen(*ans) - 1);
    strncat(*ans, partial_label, MAX_STR_LENGTH - strlen(*ans) - 1);
    if (*buffer > 0)
        strncat(*ans, " ", MAX_STR_LENGTH - strlen(*ans) - 1);
}

int say(int64_t input, char **ans)
{
    // If out of bounds, exit with error condition
    if (input > 999999999999 || input < 0)
    {
        *ans = NULL;
        return -1;
    }

    *ans = calloc(MAX_STR_LENGTH, sizeof(char));
    if (input == 0)
    {
        strncpy(*ans, "zero", MAX_STR_LENGTH - strlen(*ans) - 1);
        return 0;
    }

    int64_t buffer = input;

    // Billions, Millions, Thousands are 0-999 plus a trailing keyword
    if (buffer < 1000000000000 && buffer >= 1000000000)
        stringify_partial(&buffer, ans, 1000000000, "billion");
    if (buffer < 1000000000 && buffer >= 1000000)
        stringify_partial(&buffer, ans, 1000000, "million");
    if (buffer < 1000000 && buffer >= 1000)
        stringify_partial(&buffer, ans, 1000, "thousand");

    say_to_999(buffer, ans);

    return 0;
}