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

        if (strncmp(codon, "AUG", 3) == 0) {
            result.amino_acids[result.count++] = Methionine;
        } else if (strncmp(codon, "UUU", 3) == 0 || strncmp(codon, "UUC", 3) == 0) {
            result.amino_acids[result.count++] = Phenylalanine;
        } else if (strncmp(codon, "UUA", 3) == 0 || strncmp(codon, "UUG", 3) == 0) {
            result.amino_acids[result.count++] = Leucine;
        } else if (strncmp(codon, "UCU", 3) == 0 || strncmp(codon, "UCC", 3) == 0 || strncmp(codon, "UCA", 3) == 0 || strncmp(codon, "UCG", 3) == 0) {
            result.amino_acids[result.count++] = Serine;
        } else if (strncmp(codon, "UAU", 3) == 0 || strncmp(codon, "UAC", 3) == 0) {
            result.amino_acids[result.count++] = Tyrosine;
        } else if (strncmp(codon, "UGU", 3) == 0 || strncmp(codon, "UGC", 3) == 0) {
            result.amino_acids[result.count++] = Cysteine;
        } else if (strncmp(codon, "UGG", 3) == 0) {
            result.amino_acids[result.count++] = Tryptophan;
        } else if (strncmp(codon, "UAA", 3) == 0 || strncmp(codon, "UAG", 3) == 0|| strncmp(codon, "UGA", 3) == 0) {
            break;
        } else {
            fprintf(stderr, "Unknown Codon %s\n", codon);
            result.valid = false;
            break;
        }
    }

    return result;
}