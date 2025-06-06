export const isArmstrongNumber = (candidate) =>
  candidate ===
  candidate
    .toString()
    .split("")
    .map((str, idx, arr) => Math.pow(str, arr.length))
    .reduce((acc, cur) => acc + cur, 0);
