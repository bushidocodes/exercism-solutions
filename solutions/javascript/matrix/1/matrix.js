export class Matrix {
  #data = [];

  constructor(text) {
    this.#data = text
      .split("\n")
      .map((row) => row.split(" ").map((c) => Number(c)));
  }

  get rows() {
    return this.#data;
  }

  get columns() {
    return this.#data[0].map((_, idx) => this.#data.map((row) => row[idx]));
  }
}
