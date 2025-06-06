const getRandomLetter = () => {
  const start = "A".charCodeAt(0);
  const offset = Math.floor(Math.random() * 26);
  return String.fromCharCode(start + offset);
};

const getRandomDigit = () => {
  return Math.floor(Math.random() * 9).toString();
};

export class Robot {
  static existingNames = [];
  #name = "";
  static generateName() {
    return [
      getRandomLetter(),
      getRandomLetter(),
      getRandomDigit(),
      getRandomDigit(),
      getRandomDigit(),
    ].join("");
  }

  reset() {
    let candidate;
    do {
      candidate = Robot.generateName();
    } while (Robot.existingNames.includes(candidate));

    Robot.existingNames.push(candidate);

    this.#name = candidate;
  }

  constructor() {
    this.reset();
  }

  get name() {
    return `${this.#name}`;
  }

  set name(value) {
    throw new Error("Name is immutable");
  }
}

Robot.releaseNames = () => {
  Robot.existingNames = [];
};
