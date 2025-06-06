export const classify = (candidate) => {
  if (candidate <= 0)
    throw new Error("Classification is only possible for natural numbers.");

  const primes = new Set();
  let high = candidate;
  for (let low = 1; low <= high; low++) {
    if (candidate % low == 0) {
      high = candidate / low;
      primes.add(low);
      primes.add(high);
    }
  }
  primes.delete(candidate);

  let aliquotSum = 0;
  primes.forEach((prime) => {
    aliquotSum += prime;
  });

  if (aliquotSum == candidate) return "perfect";
  else if (aliquotSum > candidate) return "abundant";
  else return "deficient";
};
