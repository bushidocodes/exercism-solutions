export function translate(english: string): string {
  return english.split(" ").map(word => {
    let consonantSounds = word.match(/^[^aeiouy]?(?:qu)|^[^aeiou]+(?=y)|^[^aeiou]+/);
    let consonantSound = consonantSounds && consonantSounds[0] ? consonantSounds[0] : "";
    return word.substring(consonantSound.length) + consonantSound + "ay";
  }).join(" ");
}
