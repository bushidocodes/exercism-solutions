interface Input {
  maxFactor: number
  minFactor?: number
}

class Palindromes{
  #minFactor: number;
  #maxFactor: number;
  
  #didComputeLargest: boolean = false;
  #largestProduct: number | null = null;
  #largestProductFactors: number[][] = [];
  
  #didComputeSmallest: boolean = false;
  #smallestProduct: number | null = null;
  #smallestProductFactors: number[][] = [];

  static isPalindrome(input: number){
    let inputStr: string = `${input}`;
    return inputStr === inputStr.split("").reverse().join("");
  }
  
  constructor(params: Input){
    this.#minFactor = params.minFactor || 1;
    this.#maxFactor = params.maxFactor;
  }

  get largest(){
    if (this.#minFactor > this.#maxFactor) throw new Error("min must be <= max");

    if (!this.#didComputeLargest){
      let largest = Number.NEGATIVE_INFINITY;
      let factors: number[][] = [];
  
      for (let i: number = this.#maxFactor; i >= this.#minFactor; i--){
        for (let j: number = this.#maxFactor; j >= i; j--){
          let product = i * j;
          if (product >= largest && Palindromes.isPalindrome(product)){
            if (product > largest){
              largest = product;
              factors = [[i, j]];
            } else {
              factors.push([i, j]);
            }
          }
        }
      }

      if (largest != Number.NEGATIVE_INFINITY){
        this.#largestProduct = largest;
        this.#largestProductFactors = factors;
      }
  
      this.#didComputeLargest = true;
    }

    return {value: this.#largestProduct, factors: this.#largestProductFactors};
  }

  get smallest(){
    if (this.#minFactor > this.#maxFactor) throw new Error("min must be <= max");

    if (!this.#didComputeSmallest){
      let smallest = Number.POSITIVE_INFINITY;
      let factors: number[][] = [];
  
      for (let i: number = this.#minFactor; i <= this.#maxFactor; i++){
        for (let j: number = i; j <= this.#maxFactor; j++){
          let product = i * j;
          if (product <= smallest && Palindromes.isPalindrome(product)){
            if (product < smallest){
              smallest = product;
              factors = [[i, j]];
            } else {
              factors.push([i, j]);
            }
          }
        }
      }
  
      if (smallest != Number.POSITIVE_INFINITY){
        this.#smallestProduct = smallest;
        this.#smallestProductFactors = factors;
      }
      
      this.#didComputeSmallest = true;
    }
    
    return {value: this.#smallestProduct, factors: this.#smallestProductFactors};
  }
}

export function generate(params: Input): Palindromes {
  return new Palindromes(params);
}
