let delimiter = /[\s-]+/;
let firstChar = /[^a-zA-Z]*([a-zA-Z])/;

export const parse = (phrase) => {
  return phrase
    .split(delimiter)
    .map((word) => {
      const matches = word.match(firstChar);
      return matches != null || matches.length > 1 ? matches[1] : "";
    })
    .join("")
    .toUpperCase();
};
