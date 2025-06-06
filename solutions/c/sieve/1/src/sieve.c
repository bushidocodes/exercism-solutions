#include "sieve.h"
#include <stdio.h>

uint32_t
sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
    uint32_t num_primes = 0;

    if (limit < 2)
        return num_primes;

    enum interval_state interval[limit + 1];
    for (uint32_t i = 0; i < limit; i++)
        interval[i] = IS_PRIME;

    primes[num_primes++] = 2;

    for (uint32_t prime = 2; prime <= limit && num_primes < max_primes; /* In Body*/)
    {
        // Mark Multiples as not prime
        for (uint32_t j = 2; prime * j <= limit; j++)
            if (interval[prime * j] == IS_PRIME)
                interval[prime * j] = IS_NOT_PRIME;

        // Advance to next prime
        for (prime++; prime <= limit && interval[prime] == IS_NOT_PRIME; prime++)
            ;

        // If Still in bounds and on a prime, add to results
        if (prime <= limit && interval[prime] == IS_PRIME && num_primes < max_primes)
            primes[num_primes++] = prime;
    }

    return num_primes;
}