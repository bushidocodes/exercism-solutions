const creature = [
  "",
  "fly",
  "spider",
  "bird",
  "cat",
  "dog",
  "goat",
  "cow",
  "horse",
];

const clause = [
  "",
  "",
  "It wriggled and jiggled and tickled inside her.\n",
  "How absurd to swallow a bird!\n",
  "Imagine that, to swallow a cat!\n",
  "What a hog, to swallow a dog!\n",
  "Just opened her throat and swallowed a goat!\n",
  "I don't know how she swallowed a cow!\n",
  "She's dead, of course!\n",
];

export const verse = (id: number): string => {
  let verse = "";
  verse += `I know an old lady who swallowed a ${creature[id]}.\n`;
  verse += `${clause[id]}`;
  if (creature[id] === "horse") return verse;

  while (id >= 2) {
    verse += `She swallowed the ${creature[id]} to catch the ${
      creature[id - 1]
    }${
      creature[id - 1] === "spider"
        ? " that wriggled and jiggled and tickled inside her"
        : ""
    }.\n`;
    id--;
  }

  verse += "I don't know why she swallowed the fly. Perhaps she'll die.\n";
  return verse;
}

export const verses = (start: number, end: number): string => {
  return  Array(end - start + 1)
    .fill(0)
    .map((_, i) => start + i)
    .map(i => verse(i)).join("\n")
}
