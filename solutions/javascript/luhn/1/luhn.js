export const valid = (candidate) => {
  if (/[^ 0-9]/.test(candidate)) return false;
  if (candidate.trim().length == 1) return false;

  let digits = candidate
    .split("")
    .filter((c) => /[0-9]/.test(c))
    .map((c) => Number(c));

  digits.reverse();

  let checksum = digits
    .map((c, i) => {
      if ((i + 1) % 2 === 0) {
        let temp = 2 * c;
        return temp > 9 ? temp - 9 : temp;
      } else return c;
    })
    .reduce((acc, cur) => acc + cur, 0);

  return checksum % 10 == 0;
};
