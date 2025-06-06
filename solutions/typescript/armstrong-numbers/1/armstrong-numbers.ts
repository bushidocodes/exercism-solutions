export function isArmstrongNumber(number: number): boolean {
  const numberStr: string = number.toString();
  return number === numberStr.split("")
    .map(str => Number(str) ** numberStr.length)
    .reduce((acc, cur) => acc + cur, 0);
}
