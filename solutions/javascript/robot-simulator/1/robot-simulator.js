export class InvalidInputError extends Error {
  constructor(message) {
    super();
    this.message = message || "Invalid Input";
  }
}

export class Robot {
  static bearings = ["north", "east", "south", "west"];
  #bearing = 0;
  #x = 0;
  #y = 0;

  get bearing() {
    return Robot.bearings[this.#bearing];
  }

  get coordinates() {
    return [this.#x, this.#y];
  }

  place({ x, y, direction }) {
    if (!Robot.bearings.includes(direction)) throw new InvalidInputError();

    this.#x = x;
    this.#y = y;
    this.#bearing = Robot.bearings.indexOf(direction);
  }

  advance() {
    switch (Robot.bearings[this.#bearing]) {
      case "north":
        this.#y++;
        break;
      case "east":
        this.#x++;
        break;
      case "south":
        this.#y--;
        break;
      case "west":
        this.#x--;
        break;
    }
  }

  evaluate(instructions) {
    instructions.split("").forEach((c) => {
      switch (c) {
        case "R":
          this.#bearing = (this.#bearing + 1) % Robot.bearings.length;
          break;
        case "L":
          this.#bearing =
            (this.#bearing - 1 + Robot.bearings.length) % Robot.bearings.length;
          break;
        case "A":
          this.advance();
          break;
        default:
          throw new InvalidInputError();
      }
    });
  }
}
