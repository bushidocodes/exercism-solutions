#include "grains.h"
#include <stdio.h>

// Normally, this would be a dynamic programming problem, but the specifics of this
// spec allow us to represent the board as a UINT64_MAX bitarray

uint64_t
square(uint8_t index)
{
    // Return 0 in case index is out of bounds
    if (index == 0 || index > 64)
        return 0;

    return (uint64_t)1 << (index - 1);
}

uint64_t total(void)
{
    return UINT64_MAX;
}