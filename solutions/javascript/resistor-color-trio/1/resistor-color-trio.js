const colorsToValues = {
  black: 0,
  brown: 1,
  red: 2,
  orange: 3,
  yellow: 4,
  green: 5,
  blue: 6,
  violet: 7,
  grey: 8,
  white: 9,
};

export class ResistorColorTrio {
  #value = 0;
  constructor(colors = []) {
    if (colors.length != 3) throw new Error("Invalid number of bands");
    colors.forEach((color) => {
      if (!Object.keys(colorsToValues).includes(color))
        throw new Error("invalid color");
    });
    this.#value =
      (colorsToValues[colors[0]] * 10 + colorsToValues[colors[1]]) *
      Math.pow(10, colorsToValues[colors[2]]);
  }

  get label() {
    return this.#value > 1000
      ? `Resistor value: ${this.#value / 1000} kiloohms`
      : `Resistor value: ${this.#value} ohms`;
  }
}
