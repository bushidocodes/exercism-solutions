type Position = readonly [number, number]

type Positions = {
  white: Position
  black: Position
}
export class QueenAttack {
  public readonly black: Position
  public readonly white: Position

  constructor({white = [7, 3], black = [0, 3]}: Partial<Positions> = {white: [7, 3], black: [0, 3]}) {
    if (white[0] < 0 || white[0] > 7 || white[1] < 0 || white[1] > 7) {
        throw new Error("Queen must be placed on the board");
    }
    if (black[0] < 0 || black[0] > 7 || black[1] < 0 || black[1] > 7) {
        throw new Error("Queen must be placed on the board");
    }
    if (white[0] == black[0] && white[1] == black[1]) {
        throw new Error("Queens cannot share the same space");
    }
    this.white = white;
    this.black = black;
  }

  toString() {
    let matrix: string[][] = [];
    for (let x = 0; x < 8; x++){
      matrix[x] = [];
      for (let y = 0; y < 8; y++){
        if (this.black[0] == x && this.black[1] == y) matrix[x][y] = 'B';
        else if (this.white[0] == x && this.white[1] == y) matrix[x][y] = 'W';
        else matrix[x][y] = '_';
      }
    }
    
    return matrix.map(row => row.join(" ")).join("\n");
  }

  get canAttack() {
    if (!this.white || !this.black) return false;
    
    let xDelta = this.white[0] - this.black[0];
    let yDelta = this.white[1] - this.black[1];
    
    if (xDelta < 0) xDelta *= -1;
    if (yDelta < 0) yDelta *= -1;
    
    return (this.white[0] == this.black[0] || this.white[1] == this.black[1] || xDelta == yDelta);
  }
}
