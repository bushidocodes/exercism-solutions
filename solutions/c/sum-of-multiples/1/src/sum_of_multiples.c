#include "sum_of_multiples.h"
#include <stdio.h>

unsigned int sum_of_multiples(const unsigned int *multiples,
                              const size_t number_of_multiples,
                              const unsigned int up_to)
{
    unsigned int sum = 0;
    if (multiples == NULL)
        return sum;

    for (size_t i = 1; i < up_to; i++)
    {
        for (size_t j = 0; j < number_of_multiples; j++)
        {
            // Protect against divide by 0
            if (multiples[j] == 0)
                continue;
            if (i % multiples[j] == 0)
            {
                sum += i;
                // Ensure we only add a number once if a multiple of several numbers
                break;
            }
        }
    }
    return sum;
}