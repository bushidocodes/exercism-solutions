export class List extends Array {
  constructor(elements = []) {
    if (elements.length > 0) super(...elements);
    else super();
  }

  compare(list) {
    if (this.length === 0 && list.length == 0) return "EQUAL";
    if (this.length === 0 && list.length > 0) return "SUBLIST";
    if (this.length > 0 && list.length === 0) return "SUPERLIST";

    if (this.length === list.length) {
      return this.every((elem, idx) => elem === list[idx])
        ? "EQUAL"
        : "UNEQUAL";
    } else if (this.length < list.length) {
      for (let i = 0; i <= list.length - this.length; i++) {
        if (
          list
            .slice(i, i + this.length)
            .every((elem, idx) => elem === this[idx])
        )
          return "SUBLIST";
      }
    } else if (this.length > list.length) {
      for (let i = 0; i <= this.length - list.length; i++) {
        if (
          this.slice(i, i + list.length).every(
            (elem, idx) => elem === list[idx]
          )
        )
          return "SUPERLIST";
      }
    }

    return "UNEQUAL";
  }
}
