export class Clock {
  #date;
  constructor(hours = 0, minutes = 0) {
    this.#date = new Date();
    this.#date.setHours(hours);
    this.#date.setMinutes(minutes);
  }

  toString() {
    let hours = `${this.#date.getHours()}`.padStart(2, "0");
    let minutes = `${this.#date.getMinutes()}`.padStart(2, "0");
    return `${hours}:${minutes}`;
  }

  plus(minutes) {
    this.#date.setMinutes(this.#date.getMinutes() + minutes);
    return this;
  }

  minus(minutes) {
    this.#date.setMinutes(this.#date.getMinutes() - minutes);
    return this;
  }

  equals(other) {
    return this.toString() == other.toString();
  }
}
