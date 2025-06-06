export function primes(limit: number) {
  if (limit < 2) return [];

  let primes: Set<number> = new Set();
  for (let i = 2; i <= limit; i++) {
    primes.add(i);
  }

  for (let i = 2; i <= limit; i++){
    if (primes.has(i)) {
      for (let j = 2; i * j <= limit; j++) primes.delete(i * j);
    }
  }

  return Array.from(primes);
}
