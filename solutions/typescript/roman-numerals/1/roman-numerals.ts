export const toRoman = (input: number): string => {
  let output = "";
  
  while (input > 0) {
    if (input >= 1000){
      output += "M";
      input -= 1000;
    } else if (input >= 900){
      output += "CM";
      input -= 900;
    } else if (input >= 500){
      output += "D";
      input -= 500;
    } else if (input >= 400){
      output += "CD";
      input -= 400;
    } else if (input >= 100){
      output += "C";
      input -= 100;
    } else if (input >= 90){
      output += "XC";
      input -= 90;
    } else if (input >= 50){
      output += "L";
      input -= 50;
    } else if (input >= 40){
      output += "XL";
      input -= 40;
    } else if (input >= 10){
      output += "X";
      input -= 10;
    } else if (input >= 9){
      output += "IX";
      input -= 9;
    } else if (input >= 5){
      output += "V";
      input -= 5;
    } else if (input >= 4){
      output += "IV";
      input -= 4;
    } else if (input >= 1){
      output += "I";
      input -= 1;
    }
  }

  return output;
}
