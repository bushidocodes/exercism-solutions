// Converted this C example code to JS
// https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Example_3
// I do not yet grok this! YOLO
export const squareRoot = (num) => {
  let res = 0;
  let bit = 1 << 30;

  while (bit > num) bit >>= 2;

  while (bit != 0) {
    if (num >= res + bit) {
      num -= res + bit;
      res = (res >> 1) + bit;
    } else res >>= 1;
    bit >>= 2;
  }
  return res;
};
