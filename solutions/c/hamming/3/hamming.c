#include "hamming.h"
#include <stdlib.h>
#include <string.h>

int compute(const char *lhs, const char *rhs) {
    if (lhs == NULL || rhs == NULL) return -1;

    size_t strand_length;
    if ((strand_length = strlen(lhs)) != strlen(rhs)) return -1;

    int hamming_distance = 0;
    for (unsigned int i = 0; i < strand_length; i++) {
        if (lhs[i] != rhs[i]) hamming_distance++;
    }

    return hamming_distance;
}
