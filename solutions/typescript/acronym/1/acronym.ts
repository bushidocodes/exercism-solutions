export function parse(phrase: string): string {
  return phrase
    .replace(/[-:,]/, " ")
    .replace(/[a-z][A-Z]/, match => `${match.charAt(0)} ${match.charAt(1).toLowerCase()}`)
    .split(" ").map(word => word.slice(0,1).toUpperCase()).join("");
}
