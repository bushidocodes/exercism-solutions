export class Rational {
  private a: number;
  private b: number;

  constructor(a: number, b: number) {
    if (b == 0) throw new Error();

    this.a = a;
    this.b = b;
  }

  add(other: Rational): Rational {
    return new Rational(this.a * other.b + other.a * this.b, this.b * other.b).reduce();
  }

  sub(other: Rational): Rational {
    return new Rational(this.a * other.b - other.a * this.b, this.b * other.b).reduce();
  }

  mul(other: Rational): Rational {
    return new Rational(this.a * other.a, this.b * other.b).reduce();
  }

  div(other: Rational): Rational {
    return new Rational(this.a * other.b, other.a * this.b).reduce();
  }

  abs(): Rational {
    return new Rational(Math.abs(this.a), Math.abs(this.b)).reduce();
  }

  exprational(power: number) {
    if (power >= 0){
      return new Rational(this.a ** power, this.b ** power).reduce();
    } else {
      return new Rational(this.b ** Math.abs(power), this.a ** Math.abs(power)).reduce();
    }
  }

  expreal(base: number): number {
    // The sqrt and cbrt builtins offer better precision.
    switch (this.b){
      case 2:
        return Math.sqrt(base ** this.a);
      case 3:
        return Math.cbrt(base ** this.a);
      default:
        return (base ** this.a) ** (1 / this.b);
    }
  }

  reduce() {
    let max = this.a > this.b ? this.a : this.b;

    /* Reduce numerator of zero */
    if (this.a === 0){
      this.a = 0;
      this.b = 1;
      return this;
    }

    /* Shift sign to numerator */
    if (this.b < 0){
      this.a *= -1;
      this.b *= -1;
    }

    /* Factor */
    for (let i = 2; i <= max; i++){
      if (this.a % i == 0 && this.b % i == 0){
        this.a /= i;
        this.b /= i;
        max = this.a > this.b ? this.a : this.b;
      }
    }
    
    return this;
  }
}
