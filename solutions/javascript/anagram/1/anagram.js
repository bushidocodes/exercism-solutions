export const findAnagrams = (word, candidates) => {
  let sortedLetters = word.toLowerCase().split("").sort().join("");

  return candidates
    .filter((c) => c.toLowerCase().split("").sort().join("") == sortedLetters)
    .filter((c) => c.toLowerCase() != word.toLowerCase());
};
