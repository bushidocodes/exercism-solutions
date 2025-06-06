export class Triangle {
  sides: number[] = [];
  
  constructor(...sides: number[]) {
    this.sides = sides.sort();
  }

  get isDegenerate() {
    if (this.sides.some(side => side === 0)) return true;
    if (this.sides[0] + this.sides[1] <= this.sides[2]) return true;

    return false;
  }

  get isEquilateral() {
    if (this.isDegenerate) return false;
    
    return new Set(this.sides).size === 1;
  }

  get isIsosceles() {
    if (this.isDegenerate) return false;
    
    return new Set(this.sides).size <= 2;
  }

  get isScalene() {
    if (this.isDegenerate) return false;
    
    return new Set(this.sides).size === 3;
  }
}
