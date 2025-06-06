#include "collatz_conjecture.h"

int steps(int start)
{
    if (start <= 0)
        return ERROR_VALUE;

    int current = start;
    int step_count = 0;

    while (current != 1)
    {
        if (current % 2 == 0)
            current /= 2;
        else
            current = 3 * current + 1;

        step_count++;
    }

    return step_count;
}