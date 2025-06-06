export const square = (i: number): bigint => {
  if (i < 1 || i > 64) throw new Error();
  return 1n << BigInt(i - 1);
}

export const total = (total: number = 64): bigint => {
  let result: bigint = 0n;
  
  for (let i = 1; i <= total; i++){
    result += square(i);  
  }

  return result;
}
