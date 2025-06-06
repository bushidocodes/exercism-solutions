export class Element {
  #value;
  #next = null;
  constructor(value) {
    this.#value = value;
  }

  get value() {
    return this.#value;
  }

  get next() {
    return this.#next;
  }
  set next(next) {
    this.#next = next;
  }
}

export class List {
  #head = null;
  #length = 0;

  constructor(list) {
    if (list != null && list.length > 0) {
      list.map((e) => new Element(e)).forEach((e) => this.add(e));
    }
  }

  add(nextValue) {
    nextValue.next = this.#head;
    this.#head = nextValue;
    this.#length++;
  }

  get length() {
    return this.#length;
  }

  get head() {
    return this.#head;
  }

  toArray() {
    const result = [];
    for (let node = this.#head; node != null; node = node.next) {
      result.push(node.value);
    }
    return result;
  }

  reverse() {
    return new List(this.toArray());
  }
}
