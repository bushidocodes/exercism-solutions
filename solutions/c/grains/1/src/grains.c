#include "grains.h"

// Using 1-based indices and index 0 is unused
#define CHESS_SQUARES 65

// Using dynamic programming, so storing partial results
static uint64_t grains_per_square[CHESS_SQUARES];
static uint8_t last_calculated = 1;

uint64_t
square(uint8_t index)
{
    // Return 0 in case index is out of bounds
    if (index == 0 || index >= CHESS_SQUARES)
        return 0;

    // Base Case
    if (index == 1)
        grains_per_square[1] = 1;

    for (int i = last_calculated + 1; i <= index; i++)
        grains_per_square[i] = grains_per_square[i - 1] * 2;

    last_calculated = index;
    return grains_per_square[index];
}

uint64_t total(void)
{
    // Call square once to ensure all partials are calculated
    uint64_t total = square(64);

    // Then add the other partials
    for (int i = 1; i <= 63; i++)
        total += grains_per_square[i];

    return total;
}