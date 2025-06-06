function checkCharacterValue(char: string): number {
  if (char == "X") return 10;
  else if (char.match(/[0-9]/)) return Number.parseInt(char);
  else throw new Error("Invalid check character");
}

export function isValid(isbn: string): boolean {
  try {
    const nonhyphens = isbn
      .split("")
      .filter(c => c != "-");

    if (nonhyphens.length < 10) return false;

    const checksum = nonhyphens
      .map((c, i) => i == 9 ? checkCharacterValue(c) : Number(c) * (10 - i))
      .reduce((acc, cur) => acc + cur, 0);
    
    return checksum % 11 == 0;
  } catch (err) {
    return false;
  }

}
