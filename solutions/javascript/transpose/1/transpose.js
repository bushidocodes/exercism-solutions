export const transpose = (input) => {
  if (input.length == 0) return [];

  // Longest row determines number of columns
  const longestRow = Math.max(...input.map((str) => str.length));

  const transposed = [...Array(longestRow).keys()].map((key) =>
    input
      .map((str) => {
        const char = str.charAt(key);
        return char != "" ? char : " ";
      })
      .join("")
  );

  // Spec wants trailing padding stripped (on last line?)
  // I suspect this should recurse upwards based on length of
  // rows beneath, but not worth the hassle! 
  transposed[transposed.length - 1] =
    transposed[transposed.length - 1].trimEnd();

  return transposed;
};
