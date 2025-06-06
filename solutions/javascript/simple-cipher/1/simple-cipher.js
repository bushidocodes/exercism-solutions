export class Cipher {
  #key = "";

  constructor(key = "aaaaaaaaaa") {
    this.#key = key;
  }

  encode(plaintext) {
    return plaintext
      .split("")
      .map((c, i) => {
        let current = c.charCodeAt(0) - "a".charCodeAt(0);
        let shift =
          this.key.charCodeAt(i % this.key.length) - "a".charCodeAt(0);
        let shifted = current + shift;
        if (shifted >= 26) shifted -= 26;
        return String.fromCharCode(shifted + "a".charCodeAt(0));
      })
      .join("");
  }

  decode(ciphertext) {
    return ciphertext
      .split("")
      .map((c, i) => {
        let current = c.charCodeAt(0) - "a".charCodeAt(0);
        let shift =
          this.key.charCodeAt(i % this.key.length) - "a".charCodeAt(0);
        let shifted = current - shift;
        if (shifted < 0) shifted += 26;
        return String.fromCharCode((shifted % 26) + "a".charCodeAt(0));
      })
      .join("");
  }

  get key() {
    return this.#key;
  }
}
