type nicomachus = "perfect" | "abundant" | "deficient";

function factor(num: number): Set<number> {
  let factors: Set<number> = new Set();
  let high = num;
  let low = 1
  for(let low = 0; low < high; low ++) {
    if (num % low == 0) {
      factors.add(low);
      high = num / low;
      if (high != num) factors.add(high);
    }
  }

  return factors;

}

export function classify(num: number): nicomachus {
  if (num < 1) throw new Error("Classification is only possible for natural numbers.");
  let factors = factor(num);
  let sum = [...factors].reduce((sum, factor) => sum + factor, 0);

  if (sum === num) {
    return "perfect";
  } else if (sum > num) {
    return "abundant";
  } else {
    return "deficient";
  }
}
