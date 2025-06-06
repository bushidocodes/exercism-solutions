export const isIsogram = (phrase) => {
  let letters = new Set();

  return phrase
    .split("")
    .map((e) => e.toLowerCase())
    .filter((e) => /[a-z]/.test(e))
    .every((e) => {
      if (letters.has(e)) return false;
      else {
        letters.add(e);
        return true;
      }
    });
};
