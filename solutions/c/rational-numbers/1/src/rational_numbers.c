#include "rational_numbers.h"
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

rational_t add(rational_t r1, rational_t r2)
{
    assert(r1.denominator != 0);
    assert(r2.denominator != 0);

    rational_t result = (rational_t){
        .numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator,
        .denominator = r1.denominator * r2.denominator};

    return reduce(result);
}

rational_t subtract(rational_t r1, rational_t r2)
{
    assert(r1.denominator != 0);
    assert(r2.denominator != 0);

    rational_t result = (rational_t){
        .numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator,
        .denominator = r1.denominator * r2.denominator};

    return reduce(result);
}

rational_t multiply(rational_t r1, rational_t r2)
{
    assert(r1.denominator != 0);
    assert(r2.denominator != 0);

    rational_t result = (rational_t){
        .numerator = r1.numerator * r2.numerator,
        .denominator = r1.denominator * r2.denominator};

    return reduce(result);
}

rational_t divide(rational_t r1, rational_t r2)
{
    assert(r1.denominator != 0);
    assert(r2.denominator != 0);

    rational_t result = (rational_t){
        .numerator = r1.numerator * r2.denominator,
        .denominator = r1.denominator * r2.numerator};

    return reduce(result);
}

rational_t absolute(rational_t r1)
{
    assert(r1.denominator != 0);

    rational_t result = (rational_t){
        .numerator = abs(r1.numerator),
        .denominator = abs(r1.denominator)};

    return reduce(result);
}

rational_t exp_rational(rational_t r1, uint16_t n)
{
    assert(r1.denominator != 0);

    rational_t result = (rational_t){
        .numerator = pow(r1.numerator, n),
        .denominator = pow(r1.denominator, n)};

    return reduce(result);
}

float exp_real(uint16_t x, rational_t r)
{
    return pow(pow(x, r.numerator), (float)1 / r.denominator);
}

rational_t reduce(const rational_t r1)
{
    assert(r1.denominator != 0);
    rational_t result = (rational_t){
        .numerator = r1.numerator,
        .denominator = r1.denominator};

    // If zero, return immediately
    if (result.numerator == 0)
    {
        result.denominator = 1;
        return result;
    }

    // What is smaller?
    bool numerator_is_smallest = abs(result.numerator) <= abs(result.denominator);
    int smallest = numerator_is_smallest ? result.numerator : result.denominator;
    int largest = !numerator_is_smallest ? result.numerator : result.denominator;

    // Are they equal?
    if (smallest == largest)
        result = (rational_t){
            .numerator = 1,
            .denominator = 1};
    // Is larger cleanly divisible by smaller?
    else if (largest % smallest == 0)
    {
        result = (rational_t){
            .numerator = numerator_is_smallest ? 1 : largest / smallest,
            .denominator = !numerator_is_smallest ? 1 : largest / smallest};
    }
    // Actually factor stuff out
    else
    {
        const int FACTORS_CAPACITY = 20;
        int factors[FACTORS_CAPACITY];
        int factors_size = 0;

        // Get the positive factors of the smaller (absolute) thing between 2..half
        int buffer = abs(smallest);
        for (int i = 2; i <= abs(smallest) / 2; i++)
        {
            if (buffer % i == 0)
            {
                buffer /= i;
                // If our static buffer is out of space, crash program
                if (factors_size + 1 == FACTORS_CAPACITY)
                    exit(EXIT_FAILURE);

                factors[factors_size++] = i;
            }

            if (buffer < 2)
                break;
        }

        // Now check if larger is cleanly divisible. If so, reduce
        for (int i = 0; i < factors_size; i++)
        {
            if (largest % factors[i] == 0)
            {
                result.numerator /= factors[i];
                result.denominator /= factors[i];
            };
        }
    }

    // If denominator is negative, factor out -1
    if (result.denominator < 0)
    {
        result.numerator *= -1;
        result.denominator *= -1;
    }

    return result;
}