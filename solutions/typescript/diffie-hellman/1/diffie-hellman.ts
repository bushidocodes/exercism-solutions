export class DiffieHellman {
  private p: number;
  private g: number;

  
  static isPrime(num: number): boolean {
    for (let i = 2; i < Math.floor(num / 2); i++){
      if (num % i == 0) return false;
    }

    return true;
  }
  
  constructor(p: number, g: number) {
    if (p < 1 || p > 9998 || g < 1 || p > 9998 ) throw new Error();
    if (!DiffieHellman.isPrime(p) || !DiffieHellman.isPrime(g)) throw new Error();

    this.p = p;
    this.g = g;
  }

  public getPublicKey(privateKey: number): number {
    if (privateKey <= 1 || privateKey >= this.p) throw new Error();
    return (this.g ** privateKey) % this.p;
  }

  public getSecret(theirPublicKey: number, myPrivateKey: number): number {
    return (theirPublicKey ** myPrivateKey) % this.p;
  }
}
