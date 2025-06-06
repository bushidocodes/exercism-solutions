export class Robot {
  public static names = new Set<string>();
  private _name: string = "";
  
  constructor() {
    this.resetName();
  }

  public get name(): string {
    return this._name;
  }

  public resetName(): void {
    const aCharCode = "A".charCodeAt(0);
    let candidateName;

    do {
      let letters: string = String.fromCharCode( aCharCode + Math.floor(Math.random() * 26), aCharCode + Math.floor(Math.random() * 26));
      let numbers: string = Math.floor(Math.random() * 1000).toString().padStart(3, "0");
      candidateName = `${letters}${numbers}`;
    } while (Robot.names.has(candidateName));
    
    this._name = candidateName;
    Robot.names.add(candidateName);
  }

  public static releaseNames(): void {
    Robot.names.clear();
  }

}
