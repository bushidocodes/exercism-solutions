#include "atbash_cipher.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static inline char encode(char source)
{
    return 'z' - (tolower(source) - 'a');
}

static inline char decode(char source)
{
    return 'a' + ('z' - source);
}

char *atbash_encode(const char *input)
{
    size_t input_length = strlen(input);
    char *result = calloc(input_length + 1, sizeof(char));
    size_t result_length = 0;

    for (size_t i = 0; i < input_length; i++)
    {
        if (isalpha(input[i]))
            result[result_length++] = encode(input[i]);
        else if (isdigit(input[i]))
            result[result_length++] = input[i];
        if ((result_length + 1) % 6 == 0)
        {
            // Scan forward to make sure we're not the last letter to avoid inserting a trailing space
            bool is_last_letter = true;
            for (size_t k = i + 1; k < input_length; k++)
                if (isalnum(input[k]))
                {
                    is_last_letter = false;
                    break;
                }

            if (!is_last_letter)
                result[result_length++] = ' ';
        }
    }

    result[result_length++] = '\0';
    return result;
}
char *atbash_decode(const char *input)
{
    size_t input_length = strlen(input);
    char *result = calloc(input_length + 1, sizeof(char));
    size_t result_length = 0;

    for (size_t i = 0; i < input_length; i++)
    {
        if (isalpha(input[i]))
            result[result_length++] = decode(input[i]);
        else if (isdigit(input[i]))
            result[result_length++] = input[i];
    }

    result[result_length++] = '\0';
    return result;
}