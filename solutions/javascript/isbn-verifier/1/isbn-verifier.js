export const isValid = (input) => {
  const digits = input.split("").filter((e) => e != "-");

  if (digits.length !== 10) return false;
  let isInvalid = digits.some((e, idx) =>
    idx < 9 ? !/[0-9]/.test(e) : !/[0-9X]/.test(e)
  );
  if (isInvalid) return false;

  const checksum =
    digits
      .map((e) => (e == "X" ? 10 : e))
      .map((e, i) => e * (9 - i + 1))
      .reduce((acc, cur) => acc + cur, 0) % 11;

  return checksum == 0;
};
