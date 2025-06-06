export class House {
  static nouns = [
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
  static verbs = [
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

  static verse(number) {
    const result = [];
    result.push(`This is the ${House.nouns[number]}`);

    for (let i = number - 1; i >= 1; i--) {
      result.push(`that ${House.verbs[i]} the ${House.nouns[i]}`);
    }

    result[result.length - 1] = result[result.length - 1].concat(".");

    return result;
  }

  static verses(startVerse, endVerse) {
    const result = [];
    for (let verseIdx = startVerse; verseIdx <= endVerse; verseIdx++) {
      result.push(...House.verse(verseIdx));
      if (verseIdx < endVerse) result.push("");
    }

    return result;
  }
}
