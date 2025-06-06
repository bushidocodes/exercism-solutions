export function transform(oldRepresentation: {[key: string]: string[]}): { [key: string]: number } {
  let result: { [key: string]: number} = {};
  for (let value of Object.keys(oldRepresentation)) {
    for (let letter of oldRepresentation[value]) {
      result[letter.toLowerCase()] = Number(value);
    }
  }

  return result;
}
