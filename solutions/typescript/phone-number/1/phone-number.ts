export function clean(dirtyInput: string): string {
  let digits = dirtyInput
    .split("")
    .filter(c => {
      // Validate Characters
      if (c.match(/[a-zA-Z]/)) throw new Error("Letters not permitted");
      else if (!c.match(/[+\(\)\-. 0-9]/)) throw new Error("Punctuations not permitted");

      return c.match(/[0-9]/);
    });

  // Validate Length
  if (digits.length < 7 || digits.length == 9) throw new Error("Incorrect number of digits");
  if (digits.length > 11) throw new Error("More than 11 digits");

  // Strip leading 1 in 1-900-999-9999
  if (digits.length == 11) {
    if (digits[0] != "1") throw new Error("11 digits must start with 1");
    digits = digits.slice(1);
  } 

  if (digits.length == 10){
    if (digits[0] == "0") throw new Error("Area code cannot start with zero");
    if (digits[0] == "1") throw new Error("Area code cannot start with one");
    if (digits[3] == "0") throw new Error("Exchange code cannot start with zero");
    if (digits[3] == "1") throw new Error("Exchange code cannot start with one");
  }

  // Validate 999-9999
  if (digits.length == 7){
    if (digits[0] == "0") throw new Error("Exchange code cannot start with zero");
    if (digits[0] == "1") throw new Error("Exchange code cannot start with one");
  }
    
  return digits.join("");
}
