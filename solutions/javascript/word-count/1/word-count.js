const delimiter = /[^a-zA-Z1-9']+/;

export const countWords = (input) => {
  return input
    .split(delimiter)
    .filter((e) => e != "")
    .map((e) => e.toLowerCase())
    .map((e) =>
      e.charAt(0) == "'" && e.charAt(e.length - 1) == "'"
        ? e.substring(1, e.length - 1)
        : e
    )
    .reduce((acc, cur) => {
      if (acc[cur] == undefined) acc[cur] = 1;
      else acc[cur]++;
      return acc;
    }, {});
};
