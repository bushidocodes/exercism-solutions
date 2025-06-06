export function isIsogram(str: string): boolean {
  let chars = str
    .split("")
    .filter(c => !c.match(/[\s-]/))
    .map(c => c.toLowerCase());
  
  return chars.length === new Set(chars).size;
}
