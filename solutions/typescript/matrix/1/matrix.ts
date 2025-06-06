export class Matrix {
  _rows: number[][];
  constructor(data: string) {
    this._rows = data.split("\n").map(row => row.split(" ").map(e => Number(e)));
  }

  get rows(): number[][] {
    return this._rows;
  }

  get columns(): number[][] {
    let columns = [];
    for (let i = 0; i < this._rows[0].length; i++) {
      columns[i] = this._rows.map(row => row[i]);
    }

    return columns;
  }
}
