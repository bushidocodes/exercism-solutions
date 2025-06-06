#ifndef PYTHAGOREAN_TRIPLET
#define PYTHAGOREAN_TRIPLET

#include <stdint.h>

typedef struct
{
    int a;
    int b;
    int c;
} triplet_t;

typedef struct
{
    uint16_t count;
    triplet_t *triplets;
} triplets_t;

triplets_t *triplets_with_sum(uint16_t sum);
void free_triplets(triplets_t *t);

#endif
