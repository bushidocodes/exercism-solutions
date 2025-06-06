export class Series {
  #series;

  constructor(series) {
    if (series.length == 0) throw new Error("series cannot be empty");

    this.#series = series.split("").map((c) => Number(c));
  }

  slices(sliceLength) {
    if (sliceLength < 0) throw new Error("slice length cannot be negative");
    if (sliceLength == 0) throw new Error("slice length cannot be zero");
    if (sliceLength > this.#series.length)
      throw new Error("slice length cannot be greater than series length");

    const slices = [];
    for (let i = 0; i + sliceLength <= this.#series.length; i++) {
      slices.push(this.#series.slice(i, i + sliceLength));
    }
    return slices;
  }
}
