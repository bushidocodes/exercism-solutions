#include "rna_transcription.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _POSIX_C_SOURCE = 200809L

char *to_rna(const char *dna) {
	// strndup will be in C2X as well
#ifdef _POSIX_C_SOURCE
	char *buffer = strndup(dna, strlen(dna));
#else
	size_t dna_len = strlen(dna) + 1;
	char *buffer = calloc(dna_len, sizeof(char));
	strncpy(buffer, dna, dna_len);
#endif

	for (char *c = buffer; *c != '\0'; c++) {
		switch (*c) {
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