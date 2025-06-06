const day = [
  "",
  "first",
  "second",
  "third",
  "fourth",
  "fifth",
  "sixth",
  "seventh",
  "eighth",
  "ninth",
  "tenth",
  "eleventh",
  "twelfth",
];

const newGift = [
  "",
  "a Partridge in a Pear Tree",
  "two Turtle Doves",
  "three French Hens",
  "four Calling Birds",
  "five Gold Rings",
  "six Geese-a-Laying",
  "seven Swans-a-Swimming",
  "eight Maids-a-Milking",
  "nine Ladies Dancing",
  "ten Lords-a-Leaping",
  "eleven Pipers Piping",
  "twelve Drummers Drumming",
];

const gift = (day) => {
  if (day == 1) return newGift[day];
  // range is day .. 2 and day 1 is concatenated with ", and" delimiter
  const range = [...Array(day - 1).keys()].map((i) => i + 2).reverse();
  return range
    .map((i) => newGift[i])
    .join(", ")
    .concat(`, and ${newGift[1]}`);
};

export const recite = (start, end = start) => {
  // range start..end inclusive
  const range = [...Array(end - start + 1).keys()].map((i) => i + start);
  return range
    .map(
      (v) =>
        `On the ${day[v]} day of Christmas my true love gave to me: ${gift(
          v
        )}.\n`
    )
    .join("\n");
};
