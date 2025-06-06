export class Say {
  static baseNumber = new Map([
    [0, "zero"],
    [1, "one"],
    [2, "two"],
    [3, "three"],
    [4, "four"],
    [5, "five"],
    [6, "six"],
    [7, "seven"],
    [8, "eight"],
    [9, "nine"],
    [10, "ten"],
    [11, "eleven"],
    [12, "twelve"],
    [13, "thirteen"],
    [14, "fourteen"],
    [15, "fifteen"],
    [16, "sixteen"],
    [17, "seventeen"],
    [18, "eighteen"],
    [19, "nineteen"],
  ]);

  static tens = new Map([
    [10, "ten"],
    [20, "twenty"],
    [30, "thirty"],
    [40, "forty"],
    [50, "fifty"],
    [60, "sixty"],
    [70, "seventy"],
    [80, "eighty"],
    [90, "ninety"],
  ]);

  static place = new Map([
    [100, "hundred"],
    [1000, "thousand"],
    [1000000, "million"],
    [1000000000, "billion"],
  ]);

  static subThousand(number) {
    let result = "";

    if (number >= 100 && number < 1000) {
      const numberOfHundreds = Math.floor(number / 100);
      result += Say.baseNumber.get(numberOfHundreds);
      result += " ";
      result += Say.place.get(100);
      number %= 100;
      if (number > 0) result += " ";
    }

    if (number >= 20 && number < 100) {
      result += Say.tens.get(Math.floor(number / 10) * 10);
      number %= 10;
      if (number > 0) result += "-";
    }

    if (number > 0 && number < 20) {
      result += Say.baseNumber.get(number);
    }
    return result;
  }

  static complexPlace(number, placeNum) {
    let result = "";
    result += Say.subThousand(Math.floor(number / placeNum));
    result += " ";
    result += Say.place.get(placeNum);
    number %= placeNum;
    if (number != 0) result += " ";

    return result;
  }

  inEnglish(number) {
    if (number < 0 || number >= 1000000000000)
      throw new Error("Number must be between 0 and 999,999,999,999.");
    if (number == 0) return "zero";

    let result = "";
    if (number >= 1000000000) {
      result += Say.complexPlace(number, 1000000000);
      number %= 1000000000;
    }
    if (number >= 1000000) {
      result += Say.complexPlace(number, 1000000);
      number %= 1000000;
    }
    if (number >= 1000) {
      result += Say.complexPlace(number, 1000);
      number %= 1000;
    }

    if (number > 0) result += Say.subThousand(number);

    return result;
  }
}
