export function proverb(...nouns: string[]): string {
  let result = "";
  for (let i: number = 0; i < nouns.length - 1; i++){
    result += `For want of a ${nouns[i]} the ${nouns[i + 1]} was lost.\n`;
  }
  result += `And all for the want of a ${nouns[0]}.`;

  return result;
}
