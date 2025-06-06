const isPrime = (num) => {
  for (let i = 2, s = Math.sqrt(num); i <= s; i++)
    if (num % i === 0) return false;
  return num > 1;
};

export class DiffieHellman {
  #p;
  #g;

  constructor(p, g) {
    if (p < 1) throw new Error("Out of range");
    if (!isPrime(p)) throw new Error(`${p} is not prime`);
    if (!isPrime(g)) throw new Error(`${g} is not prime`);

    this.#p = p;
    this.#g = g;
  }

  getPublicKey(privateKey) {
    if (privateKey <= 1 || privateKey >= this.#p)
      throw new Error("Invalid private key");
    return Math.pow(this.#g, privateKey) % this.#p;
  }

  getSecret(theirPublicKey, myPrivateKey) {
    return Math.pow(theirPublicKey, myPrivateKey) % this.#p;
  }
}
