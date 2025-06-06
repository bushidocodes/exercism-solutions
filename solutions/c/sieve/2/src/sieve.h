#ifndef SIEVE_H
#define SIEVE_H

#include <stdint.h>
#include <stddef.h>

enum interval_state
{
    IS_PRIME = 0,
    IS_NOT_PRIME = 1,
};

/// Calculate at most `max_primes` prime numbers in the interval [2,limit]
/// using the Sieve of Eratosthenes and store the prime numbers in `primes`
/// in increasing order.
/// The function returns the number of calculate primes.
uint32_t
sieve(uint32_t limit, uint32_t *primes, size_t max_primes);

#endif
