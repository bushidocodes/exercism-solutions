const dayDescriptors: string[] = [
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
]

const giftOfTheDay: string[] = [
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
  "twelve Drummers Drumming"
]

const verse = (day: number): string => {
  let res = `On the ${dayDescriptors[day]} day of Christmas my true love gave to me: `;

  res += Array(day)
    .fill(0)
    .map((_, i) => day - i)
    .map(i => {
      if (i === 1 && day > 1) return `and ${giftOfTheDay[i]}.\n`
      if (i === 1 && day === 1) return `${giftOfTheDay[i]}.\n`
      else return giftOfTheDay[i];
    })
    .join(", ")

  return res;
};

export function recite(start: number, end: number): string {
  return Array(end - start + 1)
    .fill(0)
    .map((c,i) => c + start + i)
    .map(i => verse(i))
    .join("");
}
