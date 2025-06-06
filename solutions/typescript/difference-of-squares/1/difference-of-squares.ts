export class Squares {
  count: number;
  constructor(count: number) {
    this.count = count;
  }

  get sumOfSquares(): number {
    return Array(this.count)
      .fill(0)
      .map((_, i: number) => (i + 1) ** 2)
      .reduce((acc: number, cur: number) => acc + cur, 0)
  }

  get squareOfSum(): number {
    return (Array(this.count)
            .fill(0)
            .map((_: number, i: number) => i + 1)
            .reduce((acc: number, cur: number) => acc + cur, 0)
           ) ** 2;
  }

  get difference(): number {
    return this.squareOfSum - this.sumOfSquares;
  }
}
