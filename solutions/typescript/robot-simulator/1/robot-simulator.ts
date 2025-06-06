export class InvalidInputError extends Error {
  constructor(message?: string) {
    super()
    this.message = message || 'Invalid Input'
  }
}

type Direction = 'north' | 'east' | 'south' | 'west'
type Coordinates = [number, number]

export class Robot {
  #bearing: Direction = 'north';
  #coordinates: Coordinates = [0, 0];
  
  get bearing(): Direction {
    return this.#bearing;
  }

  get coordinates(): Coordinates {
    return this.#coordinates;
  }

  turnRight(){
    switch(this.#bearing){
      case 'north':
        this.#bearing = 'east';
        break;
      case 'east':
        this.#bearing = 'south';
        break;
      case 'south':
        this.#bearing = 'west';
        break;
      case 'west':
        this.#bearing = 'north';
        break;
      default:
        throw new Error("Invalid bearing");
    }
  }

  turnLeft(){
    switch(this.#bearing){
      case 'north':
        this.#bearing = 'west';
        break;
      case 'west':
        this.#bearing = 'south';
        break;
      case 'south':
        this.#bearing = 'east';
        break;
      case 'east':
        this.#bearing = 'north';
        break;
      default:
        throw new Error("Invalid bearing");
    }
  }

  advance(){
    switch(this.#bearing){
      case 'north':
        this.#coordinates[1]++;
        break;
      case 'east':
        this.#coordinates[0]++;
        break;
      case 'south':
        this.#coordinates[1]--;
        break;
      case 'west':
        this.#coordinates[0]--;
        break;
      default:
        throw new Error("Invalid bearing");
    }
  }

  place(loc: { x: number; y: number; direction: string }) {
    if (loc.direction) {
      if (loc.direction !== 'north' && loc.direction !== 'east' && loc.direction !== 'south' && loc.direction !== 'west'){
        throw new InvalidInputError();
      }
      
      this.#bearing = loc.direction as Direction;
    } 
    
    if (loc.x !== undefined) this.#coordinates[0] = loc.x;
    if (loc.y !== undefined) this.#coordinates[1] = loc.y;
  }

  evaluate(instructions: string) {
    for (let instruction of instructions.split("")){
      switch(instruction){
        case 'R':
          this.turnRight();
          break;
        case 'L':
          this.turnLeft();
          break;
        case 'A':
          this.advance();
          break;
      }
    }
  }
}
