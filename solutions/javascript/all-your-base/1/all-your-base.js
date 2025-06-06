export const convert = (digits, inputBase, outputBase) => {

  if (inputBase <= 1) throw new Error('Wrong input base');
  if (outputBase <= 1) throw new Error('Wrong output base');
  if (digits.some(e => e < 0)) throw new Error("Input has wrong format");
  if (digits.some(e => e >= inputBase)) throw new Error("Input has wrong format");
  if (digits.length == 0) throw new Error("Input has wrong format");

  if (digits[0] == 0) {
    if (digits.length == 1) return [0];
    else throw new Error("Input has wrong format")
  }

  /* Convert to Decimal */
  digits.reverse();
  let total = 0;
  for (let i = 0; i <digits.length; i++){
    total += digits[i] * inputBase ** i
  };

  /* Convert to output base */
  let result = [];
  var largestExponent = Math.floor(Math.log(total) / Math.log(outputBase));
  for (let i = largestExponent; i >= 0; i--){
    let place = Math.pow(outputBase,i);
    result.push(Math.floor(total / place));
    total %= place;
  }

  return result;
};
