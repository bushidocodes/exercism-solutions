export class Triangle {
  #sides = [];
  #degenerate = false;

  constructor(...sides) {
    this.#sides = sides;

    let largest = 0;
    let largestIdx = -1;
    let sumOfRest = 0;

    this.#sides.forEach((side, idx) => {
      if (side > largest) {
        largest = side;
        largestIdx = idx;
      }
    });

    if (largest == 0) {
      this.#degenerate = true;
    } else {
      this.#sides.forEach((side, idx) => {
        if (idx != largestIdx) {
          sumOfRest += side;
        }
      });
      if (largest > sumOfRest) this.#degenerate = true;
    }
  }

  get isEquilateral() {
    if (this.#degenerate) return false;

    return this.#sides[0] == this.#sides[1] && this.#sides[1] == this.#sides[2];
  }

  get isIsosceles() {
    if (this.#degenerate) return false;

    let sidesSet = new Set(this.#sides);
    return sidesSet.size < 3;
  }

  get isScalene() {
    if (this.#degenerate) return false;

    return (
      this.#sides[0] != this.#sides[1] &&
      this.#sides[1] != this.#sides[2] &&
      this.#sides[0] != this.#sides[2]
    );
  }
}
