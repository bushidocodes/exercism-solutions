export function valid(digitString: string): boolean {
  if (digitString.length < 1) return false;
  if (digitString.trim() == "0") return false;
  
  let digits: number[] = digitString
    .split("")
    .filter(c => c !== " ")
    .map(c => Number(c));

  if (digits.some(c => Number.isNaN(c))) return false;
  
  let checksum = digits
    .map((c, i) => {
      if (i % 2 === 1) {
        c *= 2;
        if (c > 9) c -= 9;
      }
      
      return c;
    })
    .reduce((acc, cur) => acc + cur, 0);

  return checksum % 10 === 0;
}
