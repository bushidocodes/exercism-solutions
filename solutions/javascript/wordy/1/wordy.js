const prefixRegex = /^What is ?(.*)\?$/;
const numberRegex = /^([\-0-9]+)? ?(.*)/;
const operatorRegex = /^(plus|minus|multiplied\ by|divided\ by)? ?(.*)/;

export const answer = (question) => {
  let buffer = question;
  let accumulator, operator, numberStr, number, rest;

  // Match and string What is and trailing question mark
  buffer = buffer.match(prefixRegex);
  if (buffer == null) throw new Error("Unknown operation");
  [, rest] = buffer;
  if (rest == "") throw new Error("Syntax error");
  buffer = rest;

  // Match first number and load into accumulator
  [, numberStr, rest] = buffer.match(numberRegex);
  buffer = rest;
  if (!numberStr) throw new Error("Syntax error");
  accumulator = Number(numberStr);

  while (buffer) {
    // Get Operator
    [, operator, rest] = buffer.match(operatorRegex);
    buffer = rest;
    if (operator == undefined) {
      [, numberStr, rest] = buffer.match(numberRegex);
      if (numberStr) throw new Error("Syntax error");
      throw new Error("Unknown operation");
    }

    // Get Number
    [, numberStr, rest] = buffer.match(numberRegex);
    buffer = rest;
    if (!numberStr) throw new Error("Syntax error");
    number = Number(numberStr);

    // Update accumulator
    switch (operator) {
      case "plus":
        accumulator += number;
        break;
      case "minus":
        accumulator -= number;
        break;
      case "multiplied by":
        accumulator *= number;
        break;
      case "divided by":
        accumulator /= number;
        break;
      default:
        throw new Error("Unknown operation");
    }
  }

  return accumulator;
};
