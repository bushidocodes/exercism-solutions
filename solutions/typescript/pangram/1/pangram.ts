class pangram {
  private sentence: string;

  // This assumes traditional ASCII chars
  private letterCount: Record<string, number>;
  private didCompute: boolean;
  private result: boolean;

  constructor(sentence: string) {
    this.sentence = sentence;
    this.didCompute = false;
    this.result = false;
    this.letterCount = {
      a: 0,
      b: 0,
      c: 0,
      d: 0,
      e: 0,
      f: 0,
      g: 0,
      h: 0,
      i: 0,
      j: 0,
      k: 0,
      l: 0,
      m: 0,
      n: 0,
      o: 0,
      p: 0,
      q: 0,
      r: 0,
      s: 0,
      t: 0,
      u: 0,
      v: 0,
      w: 0,
      x: 0,
      y: 0,
      z: 0,
    };
  }

  isPangram(): boolean {
    if (this.didCompute === false) {
      if (this.sentence.length == 0) {
        this.result = false;
        this.didCompute = true;
        return this.result;
      } else {
        this.sentence
          .toLocaleLowerCase()
          .split("")
          .map((letter) => {
            if (this.letterCount.hasOwnProperty(letter)) {
              this.letterCount[letter]++;
            }
          });

        this.result = Object.values(this.letterCount).every(
          (count) => count >= 1
        );
        this.didCompute = true;
      }
    }

    return this.result;
  }
}

export default pangram;
