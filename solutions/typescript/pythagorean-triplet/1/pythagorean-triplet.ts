type Options = {
  minFactor?: number
  maxFactor?: number
  sum: number
}

export function triplets({sum, minFactor = 1, maxFactor = sum}: Options): Triplet[] {
  let results: Triplet[] = [];

  for (let c: number = maxFactor; c >= minFactor; c--){
    for (let a: number = minFactor; a <= c; a++){
      let b = sum - a - c;
      if (b < a) break;
      if (a*a + b*b == c*c) results.push(new Triplet(a,b,c));
    }
  }
  
  return results;
}

class Triplet {
  #data: [number, number, number];
  
  constructor(first: number, second: number, third: number) {
    this.#data = [first, second, third];
  }

  toArray(): [number, number, number] {
    return this.#data;
  }
}
