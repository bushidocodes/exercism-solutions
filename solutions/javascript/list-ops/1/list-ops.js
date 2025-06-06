export class List {
  #values = [];

  constructor(data) {
    if (data) this.#values = [...data];
  }

  get values() {
    return this.#values;
  }

  append(second) {
    return new List([...this.#values, ...second.#values]);
  }

  // Mutates lhs in order to enable recursion
  static concat(lhs, rhs) {
    for (let elem of rhs.values) {
      if (elem instanceof List == false) {
        lhs.#values.push(elem);
      } else List.concat(lhs, elem);
    }
    return this;
  }

  concat(second) {
    let result = new List([...this.values]);
    List.concat(result, second);
    return result;
  }

  filter(fn) {
    return new List(this.values.filter(fn));
  }

  map(fn) {
    return new List(this.values.map(fn));
  }

  length() {
    return this.values.length;
  }

  foldl(fn, acc_init) {
    return this.values.reduce(fn, acc_init);
  }

  foldr(fn, acc_init) {
    const temp = [...this.values];
    temp.reverse();
    return temp.reduce(fn, acc_init);
  }

  reverse() {
    const temp = [...this.values];
    temp.reverse();
    return new List(temp);
  }
}
