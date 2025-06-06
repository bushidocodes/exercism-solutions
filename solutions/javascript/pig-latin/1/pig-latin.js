export class translator {
  static word(word) {
    if (/^thr|^sch|[^aeiou]qu/.test(word))
      return word.substring(3, word.length) + word.substring(0, 3) + "ay";

    if (/^ch|^qu|^th|^rh/.test(word))
      return word.substring(2, word.length) + word.substring(0, 2) + "ay";

    if (/^[aeiou]|^yt|^xr/.test(word)) {
      return word + "ay";
    }

    return word.substring(1, word.length) + word.charAt(0) + "ay";
  }

  static translate(phrase) {
    return phrase
      .split(" ")
      .map((word) => translator.word(word))
      .join(" ");
  }
}
