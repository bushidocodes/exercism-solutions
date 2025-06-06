export const primeFactors = (number) => {
  let primes = [];

  for (let divisor = 2; divisor <= number; divisor++) {
    while (number % divisor === 0) {
      primes.push(divisor);
      number /= divisor;
    }
  }

  return primes;
};
