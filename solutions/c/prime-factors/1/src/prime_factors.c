#include "prime_factors.h"
#include "vector.h"
#include "bitmap.h"

#include <assert.h>
#include <stdlib.h>

vector_t primes;

size_t
find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
    vector_init(&primes, 2);
    vector_add(&primes, 2);
    vector_add(&primes, 3);

    uint64_t buffer = n;
    uint64_t primes_found = 0;

    // Check if divisible by initial primes
    for (uint32_t j = 0; j < vector_get_count(&primes); j++)
    {
        result_t result = vector_get_nth(&primes, j);
        if (!result.did_succeed)
            exit(EXIT_FAILURE);

        uint32_t prime = result.data;

        while (buffer % prime == 0)
        {
            factors[primes_found++] = prime;
            buffer /= prime;
        }
    }

    // Get the last prime. We use the as the denominator to reduce our search space
    uint32_t last_prime;
    result_t result = vector_get_last(&primes);
    if (result.did_succeed)
        last_prime = result.data;

    for (uint32_t candidate = last_prime + 2; candidate <= buffer / (last_prime) && primes_found < MAXFACTORS; candidate += 2)
    {
        bool is_prime = true;

        for (uint32_t j = 0; j < vector_get_count(&primes); j++)
        {
            result_t result = vector_get_nth(&primes, j);
            if (!result.did_succeed)
                exit(EXIT_FAILURE);

            uint32_t prime = result.data;

            if (candidate % prime == 0)
            {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
        {
            vector_add(&primes, candidate);

            while (buffer % candidate == 0)
            {
                factors[primes_found++] = candidate;
                buffer /= candidate;
            }
        }

        // Update last prime to keep the search space small
        result = vector_get_last(&primes);
        if (result.did_succeed)
            last_prime = result.data;
    }

    // if buffer isn't 1, the last factor is the buffer itself
    if (buffer != 1)
        factors[primes_found++] = buffer;

    vector_free(&primes);
    return primes_found;
}