export class HighScores {
  #scores = [];
  constructor(scores) {
    this.#scores = [...scores];
  }

  get scores() {
    return this.#scores;
  }

  get latest() {
    if (this.#scores.length == 0) return undefined;
    return this.#scores[this.#scores.length - 1];
  }

  get personalBest() {
    if (this.#scores.length == 0) return undefined;
    return Math.max(...this.#scores);
  }

  get personalTopThree() {
    let temp = [...this.#scores];
    temp.sort((a, b) => (a > b ? -1 : 1));
    return temp.slice(0, 3);
  }
}
