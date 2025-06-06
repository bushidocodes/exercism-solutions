export const clean = (input) => {
  // Validate
  if (/[a-zA-Z]/.test(input)) throw new Error("Letters not permitted");
  if (/[^0-9\(\)\- .+]/.test(input))
    throw new Error("Punctuations not permitted");

  // Normalize
  let digits = input
    .split("")
    .filter((c) => /\d/.test(c))
    .join("");

  // Validate Length
  if (digits.length > 11) throw new Error("More than 11 digits");
  if (digits.length <= 9) throw new Error("Incorrect number of digits");
  if (digits.length == 11) {
    if (digits.charAt(0) != 1) {
      throw new Error("11 digits must start with 1");
    } else {
      digits = digits.substring(1);
    }
  }

  // Validate leading area and exchange code digits
  if (digits.length == 10) {
    if (digits.charAt(0) == 0) {
      throw new Error("Area code cannot start with zero");
    }
    if (digits.charAt(0) == 1) {
      throw new Error("Area code cannot start with one");
    }
    if (digits.charAt(3) == 0) {
      throw new Error("Exchange code cannot start with zero");
    }
    if (digits.charAt(3) == 1) {
      throw new Error("Exchange code cannot start with one");
    }
  }

  return digits;
};
