def calculate_primes(limit = 1_000_000):
    sieve = [True] * limit
    sieve[0] = False
    sieve[1] = False

    for i in range(2, int(limit ** 0.5) + 1):
        if sieve[i]:
            for j in range (i * i, limit, i):
                sieve[j] = False

    return [idx for (idx, is_prime) in enumerate(sieve) if is_prime]

primes = calculate_primes()

def factors(value):
    temp = value
    result = []
    for prime in primes:
        while temp % prime == 0:
            result.append(prime)
            temp //= prime
    return result
