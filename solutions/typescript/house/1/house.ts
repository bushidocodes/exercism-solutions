const nouns = [
  "",
  "house that Jack built",
  "malt",
  "rat",
  "cat",
  "dog",
  "cow with the crumpled horn",
  "maiden all forlorn",
  "man all tattered and torn",
  "priest all shaven and shorn",
  "rooster that crowed in the morn",
  "farmer sowing his corn",
  "horse and the hound and the horn",
];

const verbs = [
  "",
  "lay in",
  "ate",
  "killed",
  "worried",
  "tossed",
  "milked",
  "kissed",
  "married",
  "woke",
  "kept",
  "belonged to",
];

export const verse = (number: number): string[] => {
  const result = [];
  result.push(`This is the ${nouns[number]}`);
  for (let i = number - 1; i >= 1; i--) {
    result.push(`that ${verbs[i]} the ${nouns[i]}`);
  }
  result[result.length - 1] = result[result.length - 1].concat(".");
  return result;
}

export const verses = (startVerse: number, endVerse: number): string[] => {
  const result = [];
  for (let verseIdx = startVerse; verseIdx <= endVerse; verseIdx++) {
    result.push(...verse(verseIdx));
    if (verseIdx < endVerse) result.push("");
  }
  return result;
}
