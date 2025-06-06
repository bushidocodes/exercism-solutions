export class Triangle {
  #low: number = 1;
  #high: number;
  static _rows: number[][] = [];

  static generateRow(n: number){
    
    if (n == 0) {
      Triangle._rows[0] = [1];
    } else {
      if (!Triangle._rows[n-1]) throw new Error("Previous row does not exist");
      
      Triangle._rows[n] = [...Triangle._rows[n - 1], 1];
      for (let i = n - 1; i > 0; i--){
        Triangle._rows[n][i] += Triangle._rows[n][i - 1];
      }
    }
  }

  constructor (high: number){
    if (high < this.#low) throw new Error(`number must be gte ${this.#low}`);
    this.#high = high;
  }

  get rows(){
    for (let i = Triangle._rows.length; i < this.#high; i++){
      Triangle.generateRow(i);
    }

    return Triangle._rows.slice(0, this.#high);
  }

  get lastRow(){
    for (let i = Triangle._rows.length; i < this.#high; i++){
      Triangle.generateRow(i);
    }

    return Triangle._rows[Triangle._rows.length - 1];
  }
}
