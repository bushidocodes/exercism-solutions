class RobotNameDB {
  private names: string[] = [];
  private nameIdx = 0;
  public static aCharCode = "A".charCodeAt(0);
  public static zCharCode = "Z".charCodeAt(0);

  constructor(){
    for (let i = RobotNameDB.aCharCode; i <= RobotNameDB.zCharCode; i++){
      for (let j = RobotNameDB.aCharCode; j <= RobotNameDB.zCharCode; j++){
        for (let k = 0; k < 1000; k++){
          this.names.push(`${String.fromCharCode(i,j)}${k.toString().padStart(3,"0")}`);
        }
      }  
    }
    this.shuffleNames();
  }

  public assignName(): string {
    if (this.nameIdx >= this.names.length) throw new Error("Names Exhausted");
    return this.names[this.nameIdx++];
  }

  public releaseNames(): void {
    this.nameIdx = 0;
  }

  // Based on https://exercism.org/tracks/typescript/exercises/robot-name/solutions/bobahop
  private shuffleNames(): void {
    for (let i = this.names.length; i >= 0; i--){
      let j = Math.floor(Math.random() * i);
      [this.names[i], this.names[j]] = [this.names[j], this.names[i]];
    };
  }
}

let db = new RobotNameDB();

export class Robot {
  private _name: string = "";
  
  constructor() {
    this.resetName();
  }

  public get name(): string {
    return this._name;
  }

  // throws Error when db exhausts names
  public resetName(): void {
      this._name = db.assignName();
  }

  public static releaseNames(): void {
    db.releaseNames();
  }
}

