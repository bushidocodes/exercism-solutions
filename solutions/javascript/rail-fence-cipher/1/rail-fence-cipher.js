export const encode = (plaintext, railCount) => {
  // Initialize rails as strings
  let rails = [];
  for (let i = 0; i < railCount; i++){
    rails.push("");
  }

  // Append to rail in zig-zag pattern
  let y = 0;
  let yIsDescending = true;
  for (let i = 0; i < plaintext.length; i++) {
    rails[y] += plaintext.charAt(i);
    if (y == railCount - 1) yIsDescending = false;
    if (y == 0) yIsDescending = true;
    if (yIsDescending) 
      y++;
    else
      y--;
  }

  // Append rails to generate ciphertext
  let ciphertext = "";
  for (let rail of rails){
    ciphertext += rail;
  }

  return ciphertext;
};

export const decode = (ciphertext, railCount) => {

  // Calculate offsets
  let railSizes = [];
  let y = 0;
  let yIsDescending = true;
  for (let i = 0; i < railCount; i++){
    railSizes.push(0);
  }
  for (let i = 0; i < ciphertext.length; i++) {
    railSizes[y]++;
    if (y == railCount - 1) yIsDescending = false;
    if (y == 0) yIsDescending = true;
    if (yIsDescending) 
      y++;
    else
      y--;
  }

  // Use offsets to reconstruct rails
  let rails = [];
  let cursor = 0;
  for (let i = 0; i < railCount; i++){
    rails.push(ciphertext.slice(cursor, cursor + railSizes[i]).split(""));
    cursor += railSizes[i];
  }

  // Shift from rails in Zig zag pattern
  y = 0;
  yIsDescending = true;
  let plaintext = "";

  for (let i = 0; i < ciphertext.length; i++) {
    plaintext += rails[y].shift();
    if (y == railCount - 1) yIsDescending = false;
    if (y == 0) yIsDescending = true;
    if (yIsDescending) 
      y++;
    else
      y--;
  }

  return plaintext;
};
