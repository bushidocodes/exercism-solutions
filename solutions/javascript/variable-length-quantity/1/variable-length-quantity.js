
export const encode = (numbers = []) => {
  let results = [];

  for (let num of numbers) {
    if (num == 0) {
      results.push(0);
    } else { 
      let sevenBits = [];
      while (num > 0) {
        sevenBits.unshift(num & 0b1111111);
        num >>>= 7;
      }
      // Set continuation bits
      let sequence = sevenBits.map((e, i, arr) => i != arr.length - 1 ? e | 0b10000000 : e);
      results = [...results, ...sequence]
    }
  }
  
  return results
};

const decodeChunk = (bytes) => {
  let sum = bytes
    .map((e, i, arr) => (e & 0b01111111) << (7 * (arr.length - 1 - i)))
    .reduce((acc, e) => acc + BigInt.asUintN(32, BigInt(e)), 0n);

  if (sum == 0) {
    return [0];
  } else {
    let words = [];
    while (sum > 0) {
      words.unshift(Number(BigInt.asUintN(32, sum)));
      sum >>= 32n;
    }
    return words;
  }
};

export const decode = (bytes) => {
  if (bytes.length > 0 && ((bytes[bytes.length - 1] & 0b10000000) != 0)) throw new Error("Incomplete sequence");
  
  let base = 0;
  let results = [];

  for (let i = 0; i < bytes.length; i++) {
    if ((bytes[i] & 0b10000000) == 0) {
      results = [...results, ...decodeChunk(bytes.slice(base, i + 1))];
      base = i + 1;
    }
  }

  return results;
};
