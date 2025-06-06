export class Anagram {
  input: string;
  inputSorted: string;
  
  constructor(input: string) {
    this.input = input;
    this.inputSorted = input.toLowerCase().split("").sort().join("");
  }

  public matches(...potentials: string[]): string[] {
    return potentials
      .filter(potential => potential.toLowerCase() != this.input.toLowerCase())
      .filter(potential => potential.toLowerCase().split("").sort().join("") === this.inputSorted)
  }
}
