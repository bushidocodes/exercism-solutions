const aCC = "a".charCodeAt(0);

export class SimpleCipher {
  key: string = "";

  constructor(key: string){
    if (key){
      this.key = key;
    } else {
      this.key = new Array(100)
        .fill(" ")
        .map(_ => String.fromCharCode(aCC + Math.floor(Math.random() * 26)))
        .join("");
    }
    console.log(this.key);
  }
  
  encode(plaintext: string) {
    return plaintext
      .split("")
      .map((c, i) => {
        let currentOffset = c.charCodeAt(0) - aCC;
        let shift = this.key.charCodeAt(i % this.key.length) - aCC;
        return String.fromCharCode(aCC + (currentOffset + shift) % 26);
      })
      .join("");
  }

  decode(ciphertext: string) {
    return ciphertext
      .split("")
      .map((c, i) => {
        let currentOffset = c.charCodeAt(0) - aCC;
        let shift = this.key.charCodeAt(i % this.key.length) - aCC;
        let shiftedOffset = (currentOffset - shift) % 26;
        if (shiftedOffset < 0) shiftedOffset += 26;
        return String.fromCharCode(aCC + shiftedOffset);
      })
      .join("");
  }
}
