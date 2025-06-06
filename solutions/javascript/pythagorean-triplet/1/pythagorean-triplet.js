export function triplets({ minFactor, maxFactor, sum }) {
  if (maxFactor == undefined) maxFactor = sum - 3;
  if (minFactor == undefined) minFactor = 1;

  let result = [];

  for (let c = Math.floor(sum / 3); c <= maxFactor; c++) {
    let c_sq = Math.pow(c, 2);

    let a = minFactor;
    let b = sum - c - a;
    let a_sq;
    let b_sq;
    do {
      a_sq = Math.pow(a, 2);
      b_sq = Math.pow(b, 2);
      if (a_sq + b_sq == c_sq) {
        result.push(new Triplet(a, b, c));
        break;
      }
      a++;
      b--;
    } while (a < b && a_sq + b_sq > c_sq);
  }

  result.sort((a, b) => a.data[0] - b.data[0]);

  return result;
}

class Triplet {
  #data = [];
  constructor(a, b, c) {
    this.#data = [a, b, c];
  }

  get data() {
    return this.#data;
  }

  toArray() {
    return [...this.#data];
  }
}
