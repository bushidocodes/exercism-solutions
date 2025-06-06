export class ComplexNumber {
  constructor(real = 0, imaginary = 0) {
    this.realVal = real;
    this.imaginaryVal = imaginary;
  }

  get real() {
    return this.realVal;
  }

  get imag() {
    return this.imaginaryVal;
  }

  add(second) {
    return new ComplexNumber(this.real + second.real, this.imag + second.imag);
  }

  sub(second) {
    return new ComplexNumber(this.real - second.real, this.imag - second.imag);
  }

  div(second) {
    const denominator = second.real ** 2 + second.imag ** 2;
    return new ComplexNumber(
      (this.real * second.real + this.imag * second.imag) / denominator, 
      (this.imag * second.real - this.real * second.imag) / denominator
    );
  }

  mul(second) {
    return new ComplexNumber(this.real * second.real - this.imag * second.imag, this.real * second.imag + this.imag * second.real);
  }

  get abs() {
    return (this.real ** 2 + this.imag ** 2) ** 0.5;
  }

  get conj() {
    return new ComplexNumber(this.real, this.imag == 0 ? this.imag : -this.imag);
  }

  get exp() {
    return new ComplexNumber(Math.E ** this.real, 0).mul(new ComplexNumber(Math.cos(this.imag), Math.sin(this.imag)));
  }
}
