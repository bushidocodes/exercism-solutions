export const primes = (limit) => {
  let primes = [];
  let nonPrimes = new Set();

  for (let i = 2; i <= limit; i++){
    if (!nonPrimes.has(i)) {
      primes.push(i);
      for (let j = 2; i * j <= limit; j++) {
        nonPrimes.add(i * j);
      }
    }
  }

  return primes;
};
