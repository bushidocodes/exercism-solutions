export class BinarySearchTree {
  #data: number;
  #left: BinarySearchTree | undefined;
  #right: BinarySearchTree | undefined;
  
  constructor(data: number) {
    this.#data = data;
  }

  public get data(): number {
    return this.#data;
  }

  public get right(): BinarySearchTree | undefined {
    return this.#right;
  }

  public get left(): BinarySearchTree | undefined {
    return this.#left;
  }

  public insert(item: number): void {
    if (item <= this.#data){
      if (this.#left === undefined) {
        this.#left = new BinarySearchTree(item);
      } else {
        this.#left.insert(item);
      }
    } else {
      if (this.#right === undefined) {
        this.#right = new BinarySearchTree(item);
      } else {
        this.#right.insert(item);
      }
    }
  }

  public each(callback: (data: number) => void): void {
    if (this.#left !== undefined) this.#left.each(callback);
    callback(this.#data);
    if (this.#right !== undefined) this.#right.each(callback);
  }
}
