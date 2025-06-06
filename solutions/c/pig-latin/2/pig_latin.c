#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include "pig_latin.h"
#define RESULT_CAPACITY 100

char *translate_word(const char *phrase);

char *CONSONANTS[] = {"thr", "th", "sch", "squ", "ch", "qu", "rh", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z"};
const int CONSONANT_COUNT = sizeof(CONSONANTS) / sizeof(char *);

char *EXCEPTIONS[] = {"xr", "yt"};
const int EXCEPTIONS_COUNT = sizeof(EXCEPTIONS) / sizeof(char *);

char *translate_word(const char *phrase)
{
    char *result = malloc(RESULT_CAPACITY * sizeof(char));
    char *consonant_to_move = NULL;

    for (int i = 0; i < CONSONANT_COUNT; i++)
    {
        if (strstr(phrase, CONSONANTS[i]) == phrase)
        {
            // Check for special exceptions
            for (int i = 0; i < EXCEPTIONS_COUNT; i++)
                if (strstr(phrase, EXCEPTIONS[i]) == phrase)
                    goto OUTER_BREAK;

            consonant_to_move = CONSONANTS[i];
            break;
        }
    }

OUTER_BREAK:

    if (consonant_to_move != NULL)
    {
        int consonant_length = strlen(consonant_to_move);
        strncpy(result, &phrase[consonant_length], RESULT_CAPACITY);
        strncat(result, consonant_to_move, consonant_length);
    }
    else
    {
        strncpy(result, phrase, strlen(phrase) + 1);
    }
    strncat(result, "ay", 3);
    return result;
}

char *translate(const char *phrase)
{
    // I have issues using strtok on the provided const char, so I have to copy it
    char *buffer = malloc(sizeof(phrase) + 1);
    strcpy(buffer, phrase);

    char *result = malloc(RESULT_CAPACITY * sizeof(char));
    strcpy(result, "");

    for (char *s = buffer; (s = strtok(s, " ")) != NULL; s = NULL)
    {
        char *word = translate_word(s);
        // Add spaces between words
        if (strlen(result) > 0)
            strcat(result, " ");
        strcat(result, word);
        free(word);
    }
    return result;
}