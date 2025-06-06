export const primes = (limit) => {
  if (limit < 2) return [];
  
  // Generate vector of all candidate primes;
  let candidates = new Array(limit - 1)
    .fill(0)
    .map((e,i)=> i + 2);

  // Create map to isPrime boolean with all elements set true
  let isPrime = candidates.reduce((acc, e) => acc.set(e, true), new Map());

  // Execute Sieve
  for (let candidate of candidates) {
    if (!isPrime.get(candidate)) continue;

    for (let i = 2; i * candidate <= limit; i++) {
      isPrime.set(candidate * i, false);
    }
  }

  return candidates.filter(candidate => isPrime.get(candidate));
};
