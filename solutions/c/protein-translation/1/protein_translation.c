#include "protein_translation.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>

protein_t protein(const char *const rna) {
    assert(rna != NULL);
    
    const size_t rna_len = strlen(rna);

    protein_t result = {.valid = true, .count = 0};

    for (const char *it = rna; it < rna + rna_len; it += 3){
        assert(result.count < MAX_AMINO_ACIDS);

        if (it + 2 >= rna + rna_len) {
            fprintf(stderr, "Incomplete Codon %s at idx %lu\n", it, it - rna);
            result.valid = false;
            break;
        }
        
        char codon[4] = {0};
        codon[0] = it[0];
        codon[1] = it[1];
        codon[2] = it[2];

        if (strcmp(codon, "AUG") == 0) {
            result.amino_acids[result.count++] = Methionine;
        } else if (strcmp(codon, "UUU") == 0 || strcmp(codon, "UUC") == 0) {
            result.amino_acids[result.count++] = Phenylalanine;
        } else if (strcmp(codon, "UUA") == 0 || strcmp(codon, "UUG") == 0) {
            result.amino_acids[result.count++] = Leucine;
        } else if (strcmp(codon, "UCU") == 0 || strcmp(codon, "UCC") == 0 || strcmp(codon, "UCA") == 0 || strcmp(codon, "UCG") == 0) {
            result.amino_acids[result.count++] = Serine;
        } else if (strcmp(codon, "UAU") == 0 || strcmp(codon, "UAC") == 0) {
            result.amino_acids[result.count++] = Tyrosine;
        } else if (strcmp(codon, "UGU") == 0 || strcmp(codon, "UGC") == 0) {
            result.amino_acids[result.count++] = Cysteine;
        } else if (strcmp(codon, "UGG") == 0) {
            result.amino_acids[result.count++] = Tryptophan;
        } else if (strcmp(codon, "UAA") == 0 || strcmp(codon, "UAG") == 0|| strcmp(codon, "UGA") == 0) {
            break;
        } else {
            fprintf(stderr, "Unknown Codon %s\n", codon);
            result.valid = false;
            break;
        }
    }

    return result;
}