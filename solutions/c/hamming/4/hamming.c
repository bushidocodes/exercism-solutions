#include "hamming.h"

#include <stddef.h>

int compute(const char *lhs, const char *rhs) {
    if (lhs == NULL || rhs == NULL) return -1;

    int distance = 0;
    char *lhsc, *rhsc;
    for (lhsc = (char *)lhs, rhsc = (char *)rhs; /* Skip */; lhsc++, rhsc++){
        if (*lhsc == '\0' && *rhsc == '\0') return distance;
        else if (*lhsc == '\0' || *rhsc == '\0') return -1;
        else if (*lhsc != *rhsc) distance++;
    }
}
