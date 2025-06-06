#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rna_transcription.h"
char *to_rna(const char *dna)
{
    char *buffer = strndup(dna, strlen(dna));

    for (char *c = buffer; *c != '\0'; c++)
    {
        switch (*c)
        {
        case 'G':
            *c = 'C';
            continue;
        case 'C':
            *c = 'G';
            continue;
        case 'T':
            *c = 'A';
            continue;
        case 'A':
            *c = 'U';
            continue;
        default:
            return NULL;
        }
    }

    return buffer;
}