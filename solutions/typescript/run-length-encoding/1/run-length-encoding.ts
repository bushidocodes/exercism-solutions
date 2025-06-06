export function encode(plaintext: string) {
  let encoded = "";
  let lastChar = "";
  let charCount = 0;

  for (let i = 0; i < plaintext.length; i++){
    if (plaintext.charAt(i) == lastChar){
      charCount++;
    } else {
      if (charCount == 1) encoded += lastChar;
      else if (charCount > 1) encoded += `${charCount}${lastChar}`;
      
      lastChar = plaintext.charAt(i);
      charCount = 1;
    }
  }

  if (charCount == 1) encoded += lastChar;
  else if (charCount > 1) encoded += `${charCount}${lastChar}`;
  
  return encoded;
}

export function decode(encoded: string): string {
  return encoded.replace(/[0-9]+[A-Za-z ]/g, match => {
    let letter = match.slice(-1);
    let count: number = Number(match.slice(0, -1));
    let decodedLetter = ""
    for (let i = 0; i < count; i++){
      decodedLetter += letter;
    }
    return decodedLetter;
  });
}
