export class Clock {
  hour: number;
  minute: number;
  
  constructor(hour: number, minute: number = 0) {
    this.hour = hour;
    this.minute = minute;
    this.handleCarry();
  }

  public toString(): string {
    return `${this.hour.toString().padStart(2,"0")}:${this.minute.toString().padStart(2,"0")}`;
  }

  private handleCarry(){
    while (this.minute >= 60){
      this.hour++;
      this.minute-= 60;
    }
    while (this.minute < 0){
      this.hour--;
      this.minute+= 60;
    }

    this.hour %= 24;
    while (this.hour < 0) this.hour += 24;
  }

  public plus(minutes: number): Clock {
    this.minute += minutes;
    this.handleCarry();
    return this;
  }

  public minus(minutes: number): Clock {
    this.minute -= minutes;
    this.handleCarry();
    return this;
  }

  public equals(other: Clock): boolean {
    return this.hour === other.hour && this.minute === other.minute;
  }
}
