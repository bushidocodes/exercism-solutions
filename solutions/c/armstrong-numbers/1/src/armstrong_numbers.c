#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include "armstrong_numbers.h"



int count_digits(const int source)
{
    int nDigits = 0;
    for (int buffer = source; buffer > 0; buffer /= 10)
        nDigits++;
    return nDigits;
}

int calc_candidate_armstrong_number(const int source)
{
    int result = 0;
    int nDigits = count_digits(source);
    for (int buffer = source; buffer > 0; buffer /= 10)
    {
        int digit = buffer % 10;
        result += pow(digit, nDigits);
    }
    return result;
}

int is_armstrong_number(int candidate)
{
    return (candidate == calc_candidate_armstrong_number(candidate));
}