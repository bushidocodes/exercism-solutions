export const answer = (buffer: string): number => {
  let acc = 0;

  // "Who is" is not a valid query
  let matches = buffer.match(/^What is/);
  if (!matches) throw new Error("Unknown operation");

  // If What is not followed by number, throw
  matches = buffer.match(/^What is ([-\d]+)(.+)/);
  if (!matches) throw new Error("Syntax error");

  // Set accumulator to first number
  let [full, number, rest] = matches;
  acc = Number(number);
  buffer = rest.trim();

  // Parse and update accumulator
  while (buffer != "?"){
    // If the buffer starts with a number, throw
    matches = buffer.match(/^[-\d]+.+/);
    if (matches) throw new Error("Syntax error");

    // If the buffer does not start with a known operator, throw     
    matches = buffer.match(/^plus|minus|multiplied by|divided by/);
    if (!matches) throw new Error("Unknown operation");
    
    // If number missing after operator, throw
    matches = buffer.match(/^(plus|minus|multiplied by|divided by) ([-\d]+)(.+)/);
    if (!matches) throw new Error("Syntax error");

    let [full, operation, number, rest] = matches;
    switch (operation){
      case "plus":
        acc += Number(number);
        break;
      case "minus":
        acc -= Number(number);
        break;
      case "multiplied by":
        acc *= Number(number);
        break;
      case "divided by":
        acc /= Number(number);
        break;
      default:
        throw new Error("Unknown Operation")
    }

    buffer = rest.trim();
  }

  return acc;
}
