
export class CustomSet {
  #data;
  
  constructor(elems = []) {
    this.#data = elems;
  }

  empty() {
    return this.#data.length === 0;
  }

  contains(elem) {
    return this.#data.includes(elem);
  }

  add(elem) {
    if (!this.#data.includes(elem)) this.#data.push(elem);
    return this;
  }

  subset(set) {
    return this.#data.every(e => set.#data.includes(e));
  }

  disjoint(set) {
    if (this.#data.length === 0 || set.#data.length === 0) return true; 
    
    return !this.#data.some(e => set.#data.includes(e));
  }

  eql(set) {
    if (this.#data.length === 0 && set.#data.length === 0) return true; 
    
    return this.#data.length === set.#data.length && this.#data.every(e => set.#data.includes(e));
  }

  union(set) {
    let unionSet = new CustomSet(this.#data);
    for (let e of set.#data) unionSet.add(e);

    return unionSet;
  }

  intersection(set) {
    return new CustomSet(this.#data.filter(e => set.#data.includes(e)));
  }

  difference(set) {
    return new CustomSet(this.#data.filter(e => !set.#data.includes(e)));
  }
}
