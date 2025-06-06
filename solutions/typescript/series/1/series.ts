export class Series {
  series: number[];
  constructor(series: string) {
    if (series.length == 0) throw new Error("series cannot be empty");
    this.series = series.split("").map(str => Number(str));
  }

  slices(sliceLength: number): number[][] {
    if (sliceLength < 0) throw new Error("slice length cannot be negative");
    if (sliceLength == 0) throw new Error("slice length cannot be zero");
    if (sliceLength > this.series.length) throw new Error("slice length cannot be greater than series length");
    
    let _slices: number[][] = [];
    for (let i = 0; i <= this.series.length - sliceLength; i++) {
      _slices.push(this.series.slice(i, i + sliceLength));
      console.log(_slices);
    }
    
    return _slices;
  }
}
