export class List<T> {
  #values: Array<T>
  
  constructor(input: Array<T> = []) {
    this.#values = input
  }

  static create(...values: any[]): List<any>{
    return new List(values);
  }
  
  get values(): Array<T> {
    return this.#values.slice()
  }
  
  append(other: List<T>): List<T> {
    const allValues = this.values
    other.values.forEach((value) => allValues.push(value))
    return new List(allValues)
  }
  
  concat(other: List<List<T>>): List<T> {
    return other.foldl(
      (result, list) => result.append(list),
      new List(this.values)
    )
  }
  
  filter<T1>(predicate: (el: T) => boolean): List<T> {
    return new List(this.values).foldl(
      (acc, el) => (predicate(el) ? acc.append(new List([el])) : acc),
      new List<T>()
    )
  }
  
  map<T1>(fun: (el: T) => T1): List<T1> {
    return new List(this.values).foldl(
      (acc, el) => acc.append(new List([fun(el)])),
      new List<T1>()
    )
  }

  forEach(fun: (el: T) => void): void {
    this.values.forEach(fun);
  }

  length(): number {
    let count = 0
    this.#values.forEach((_) => count++)
    return count
  }
  
  reverse(): List<T> {
    if (this.length() === 0) return this
    return new List(this.#values.slice(1))
      .reverse()
      .append(new List([this.#values[0]]))
  }

  foldl<T1,T2>(fun: (acc: T1, el: T) => T1, initial: T1): T1 {
    if (this.length() === 0) return initial
    return new List(this.#values.slice(1)).foldl(
      fun,
      fun(initial, this.#values[0])
    )
  }
  
  foldr<T1,T2>(fun: (acc: T1, el: T) => T1, initial: T1): T1 {
    if (this.length() === 0) return initial
    return fun(
      new List(this.#values.slice(1)).foldr(fun, initial),
      this.#values[0]
    )
  }
}