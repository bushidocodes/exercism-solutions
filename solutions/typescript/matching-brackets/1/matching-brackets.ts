const expectedOpening = {
  "]": "[",
  "}": "{",
  ")": "(",
}

export function isPaired(input: string): boolean {
  let stack: string[] = [];
  
  for (let c of input.split("")) {
    switch(c){
      case "[":
      case "{":
      case "(":
        stack.push(c);
        break;
      case "]":
      case "}":
      case ")":
        if (stack.pop() != expectedOpening[c]) return false;
    }
  }

  return stack.length === 0;
}
