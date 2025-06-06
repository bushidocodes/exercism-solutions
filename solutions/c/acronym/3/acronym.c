#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "acronym.h"

#define ACRONYM_CAPACITY 20

char *abbreviate(const char *phrase) {
    if (phrase == NULL || strlen(phrase) == 0) return NULL;

    char *acronym = calloc(ACRONYM_CAPACITY, sizeof(char));
    int acronym_length = 0;

    // Tokenize the phrase using ' ', '-', and '_' as delimiters
    // and add the first letter capitalized to acronym
    // strtok overwrites the source string, so allocate temporary buffer
    char buffer[strlen(phrase) + 1];
    strcpy(buffer, phrase);
    for (char *s = buffer; (s = strtok(s, " -_")) != NULL && acronym_length + 1 < ACRONYM_CAPACITY; s = NULL) {
        acronym[acronym_length++] = toupper(*s);
    }
    acronym[acronym_length++] = '\0';

    return acronym;
}