const GigasecondInMS: number = 1_000_000_000_000;

export class Gigasecond {
  private _start: number;
  
  constructor(start: Date){
    this._start = start.valueOf();
  }
  
  public date(): Date {
    return new Date(this._start + GigasecondInMS);
  }
}
