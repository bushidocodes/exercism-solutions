export class Squares {
  #firstN;
  #sumOfSquares = undefined;
  #squareOfSum = undefined;
  #difference = undefined;

  constructor(firstN) {
    this.#firstN = [...Array(firstN).keys()].map((e) => e + 1);
  }

  get sumOfSquares() {
    if (this.#sumOfSquares == undefined) {
      this.#sumOfSquares = this.#firstN
        .map((e) => e * e)
        .reduce((acc, cur) => acc + cur, 0);
    }
    return this.#sumOfSquares;
  }

  get squareOfSum() {
    if (this.#squareOfSum == undefined) {
      let sum = this.#firstN.reduce((acc, cur) => acc + cur, 0);
      this.#squareOfSum = sum * sum;
    }
    return this.#squareOfSum;
  }

  get difference() {
    if (this.#difference == undefined) {
      this.#difference = this.squareOfSum - this.sumOfSquares;
    }
    return this.#difference;
  }
}
