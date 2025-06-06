export function calculatePrimeFactors(num: number) {
  let primes: number[] = [];
  for (let divisor = 2; divisor <= num; divisor++) {
    while (num % divisor === 0) {
      primes.push(divisor);
      num /= divisor;
    }
  }
  
  return primes;
};
