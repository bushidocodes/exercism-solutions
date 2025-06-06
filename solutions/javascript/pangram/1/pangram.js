const ascii_letters = /^[a-z]$/;
const ascii_letters_count = 26;

export const isPangram = (letters) => {
  const charsUsed = letters
    .toLowerCase()
    .split("")
    .filter((char) => ascii_letters.test(char))
    .reduce((acc, cur) => acc.add(cur), new Set());

  return charsUsed.size == ascii_letters_count;
};
