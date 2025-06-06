const zCode = "z".charCodeAt(0);
const aCode = "a".charCodeAt(0);

export function encode(plainText: string): string {
  return plainText
    .split("")
    .map(c => c.toLowerCase())
    .filter(c => c.match(/[a-z0-9]/))
    .map(c => c.match(/[a-z]/) ? String.fromCharCode(zCode - (c.charCodeAt(0) - aCode)) : c)
    .map((c, i) => i > 0 && i % 5 === 0 ? ` ${c}`: c)
    .join("");
}

export function decode(cipherText: string): string {
  return cipherText
    .split("")
    .filter(c => c != " ")
    .map(c => c.match(/[a-z]/) ? String.fromCharCode(zCode - (c.charCodeAt(0) - aCode)) : c)
    .join("");
}
