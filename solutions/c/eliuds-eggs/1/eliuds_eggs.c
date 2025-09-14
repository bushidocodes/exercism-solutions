#include "eliuds_eggs.h"

#include <stddef.h>

unsigned int egg_count(unsigned int decimal){
    const size_t bit_count = sizeof(unsigned int) * 8;

    unsigned int bits_set = 0;
    for (size_t i = 0; i < bit_count; ++i) {
        unsigned int mask = 1 << i;
        if ((decimal & mask) == mask) ++bits_set;
    }

    return bits_set;
}