#include "nucleotide_count.h"
#include <malloc.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

char *count(const char *dna_strand)
{
    uint16_t a_count = 0;
    uint16_t c_count = 0;
    uint16_t g_count = 0;
    uint16_t t_count = 0;
    char *result = calloc(100, sizeof(char));

    for (uint32_t i = 0; i < strlen(dna_strand); i++)
    {
        switch (dna_strand[i])
        {
        case 'A':
            a_count++;
            continue;
        case 'C':
            c_count++;
            continue;
        case 'G':
            g_count++;
            continue;
        case 'T':
            t_count++;
            continue;
        default:
            strncpy(result, "", 1);
            return result;
        }
    }

    snprintf(&result[0], 100, "A:%d C:%d G:%d T:%d", a_count, c_count, g_count, t_count);
    return result;
}
