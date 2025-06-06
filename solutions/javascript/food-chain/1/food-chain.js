export class Song {
  static creature = [
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
  static clause = [
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
  verse(id) {
    let verse = "";
    verse += `I know an old lady who swallowed a ${Song.creature[id]}.\n`;
    verse += `${Song.clause[id]}`;
    if (Song.creature[id] === "horse") return verse;

    while (id >= 2) {
      verse += `She swallowed the ${Song.creature[id]} to catch the ${
        Song.creature[id - 1]
      }${
        Song.creature[id - 1] === "spider"
          ? " that wriggled and jiggled and tickled inside her"
          : ""
      }.\n`;
      id--;
    }

    verse += "I don't know why she swallowed the fly. Perhaps she'll die.\n";
    return verse;
  }

  verses(start, end) {
    let result = "";

    for (let i = start; i <= end; i++) {
      result += this.verse(i);
      result += "\n";
    }

    return result;
  }
}
