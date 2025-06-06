#include "rna_transcription.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

char *to_rna(const char *dna) {
	size_t dna_len = strlen(dna);
	char *rna = calloc(dna_len + 1, sizeof(char));
    assert(rna != NULL);

    for (size_t i = 0; i < dna_len; i++) {
		switch (dna[i]) {
			case 'G':
				rna[i] = 'C';
				continue;
			case 'C':
				rna[i] = 'G';
				continue;
			case 'T':
				rna[i] = 'A';
				continue;
			case 'A':
				rna[i] = 'U';
				continue;
			default:
                free(rna);
				rna = NULL;
                break;
		}
	}

	return rna;
}