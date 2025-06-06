const zero = " _ \n" + "| |\n" + "|_|\n" + "   ";
const one = "   \n" + "  |\n" + "  |\n" + "   ";
const two = " _ \n" + " _|\n" + "|_ \n" + "   ";
const three = " _ \n" + " _|\n" + " _|\n" + "   ";
const four = "   \n" + "|_|\n" + "  |\n" + "   ";
const five = " _ \n" + "|_ \n" + " _|\n" + "   ";
const six = " _ \n" + "|_ \n" + "|_|\n" + "   ";
const seven = " _ \n" + "  |\n" + "  |\n" + "   ";
const eight = " _ \n" + "|_|\n" + "|_|\n" + "   ";
const nine = " _ \n" + "|_|\n" + " _|\n" + "   ";

const convertDigit = (digitString) => {
  switch (digitString) {
    case zero:
      return "0";
    case one:
      return "1";
    case two:
      return "2";
    case three:
      return "3";
    case four:
      return "4";
    case five:
      return "5";
    case six:
      return "6";
    case seven:
      return "7";
    case eight:
      return "8";
    case nine:
      return "9";
    default:
      return "?";
  }
};

export const convert = (ocrString) => {
  let rows = ocrString.split("\n");
  let result = "";

  for (let j = 0; j < rows.length; j += 4) {
    for (let i = 0; i < rows[0].length; i += 3) {
      let digit = rows
        .slice(j, j + 4)
        .map((row) => row.slice(i, i + 3))
        .join("\n");
      result += convertDigit(digit);
    }
    if (j + 4 < rows.length) result += ",";
  }

  return result;
};
