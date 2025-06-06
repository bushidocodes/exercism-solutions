export const COLORS = [
  "black",
  "brown",
  "red",
  "orange",
  "yellow",
  "green",
  "blue",
  "violet",
  "grey",
  "white",
];

export const decodedValue = (colors) => {
  let value = 0;
  for (const color of colors.slice(0, 2)) {
    value *= 10;
    value += COLORS.indexOf(color);
  }

  return value;
};
