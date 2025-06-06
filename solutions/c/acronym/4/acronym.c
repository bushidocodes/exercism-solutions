#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "acronym.h"

#define ACRONYM_CAPACITY 20

char *abbreviate(const char *phrase) {
    if (phrase == NULL) return NULL;
    
    size_t phrase_len = strlen(phrase);
    if (phrase_len == 0) return NULL;

    char *acronym = calloc(ACRONYM_CAPACITY, sizeof(char));
    assert(acronym != NULL);
    int acronym_length = 0;

    // Tokenize the phrase using ' ', '-', and '_' as delimiters
    // and add the first letter capitalized to acronym
    // strtok overwrites the source string, so allocate temporary buffer
    char buffer[phrase_len + 1];
    strcpy(buffer, phrase);
    for (char *s = buffer; (s = strtok(s, " -_")) != NULL && acronym_length < ACRONYM_CAPACITY - 1; s = NULL) {
        acronym[acronym_length++] = toupper(*s);
    }

    assert(acronym[ACRONYM_CAPACITY - 1] == '\0');

    return acronym;
}