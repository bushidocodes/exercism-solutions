def calculate_primes(limit: int = 1_000_000) -> list[int]:
    if limit < 2:
        return []
    
    sieve = [True] * (limit + 1)
    sieve[0] = sieve[1] = False

    for i in range(2, int(limit ** 0.5) + 1):
        if sieve[i]:
            for j in range(i * i, limit + 1, i):
                sieve[j] = False

    return [idx for idx, is_prime in enumerate(sieve) if is_prime]

def primes(limit: int) -> list[int]:
    return calculate_primes(limit)
