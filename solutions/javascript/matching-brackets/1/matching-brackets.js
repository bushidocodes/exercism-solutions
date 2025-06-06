const opening = /[\({\[]/;
const closing = /[\)}\]]/;

const pairs = {
  "}": "{",
  "]": "[",
  ")": "(",
};

export const isPaired = (input) => {
  let stack = [];

  let closingHavePairs = input
    .split("")
    .filter((e) => opening.test(e) || closing.test(e))
    .every((e) => {
      if (opening.test(e)) {
        stack.push(e);
        return true;
      } else {
        return pairs[e] == stack.pop();
      }
    });

  return closingHavePairs && stack.length == 0;
};
