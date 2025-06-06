#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include "armstrong_numbers.h"

int count_digits(const int source)
{
    int digit_count = 0;
    for (int buffer = source; buffer > 0; buffer /= 10)
        digit_count++;
    return digit_count;
}

int calc_candidate_armstrong_number(const int source)
{
    int result = 0;
    int digit_count = count_digits(source);
    for (int buffer = source; buffer > 0; buffer /= 10)
    {
        int digit = buffer % 10;
        result += pow(digit, digit_count);
    }
    return result;
}

int is_armstrong_number(int candidate)
{
    return (candidate == calc_candidate_armstrong_number(candidate));
}