export class Palindromes {
  static generate({minFactor, maxFactor}) {
    if (minFactor > maxFactor) throw new Error("min must be <= max")

    let smallestPalindromeProduct = null;
    let largestPalindromeProduct = null;

    let isPalindromeNumber = num => Number.parseInt(num.toString().split("").reverse().join("")) === num;

    for (let i = minFactor; i <= maxFactor; i++){
      for (let j = minFactor; j <= maxFactor; j++){
        let product = i * j;
        if (!smallestPalindromeProduct || product < smallestPalindromeProduct || product > largestPalindromeProduct){
          if (isPalindromeNumber(product)) {
            if (!smallestPalindromeProduct) {
              smallestPalindromeProduct = product;
              largestPalindromeProduct = product;
            } else if (product < smallestPalindromeProduct){
              smallestPalindromeProduct = product;
            } else if (product > largestPalindromeProduct){
              largestPalindromeProduct = product;
            }
          }
        }
      }
    }

    const factors = new Array(maxFactor - minFactor + 1).fill(minFactor).map((e, i) => e + i);

    const calcFactors = (factors, product) => factors
          .filter(factor => product % factor === 0 && product / factor >= minFactor && product / factor <= maxFactor)
          .map(factor => ([factor, product / factor]))
          .filter(([a,b]) => a <= b)

    return {
      smallest: {
        value: smallestPalindromeProduct,
        factors: calcFactors(factors, smallestPalindromeProduct)
      },
      largest: {
        value: largestPalindromeProduct,
        factors: calcFactors(factors, largestPalindromeProduct)
      }
    }
  }
}
