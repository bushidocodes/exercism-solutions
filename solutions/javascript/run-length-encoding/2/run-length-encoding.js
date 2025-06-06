export const encode = (plain) => {
  let cur, curCount;
  let cipher = "";

  plain.split("").forEach((c, idx, arr) => {
    if (cur != c) {
      if (cur) cipher += `${curCount > 1 ? curCount : ""}${cur}`;
      cur = c;
      curCount = 1;
    } else {
      curCount++;
    }

    // If last char dump
    if (idx == arr.length - 1) {
      cipher += `${curCount > 1 ? curCount : ""}${cur}`;
    }
  });
  return cipher;
};

export const decode = (cipher) => {
  const runLengthRegex = /([0-9]*)?(.)(.+)?/;
  let result = "";
  for (
    let buffer = cipher.match(runLengthRegex);
    !!buffer;
    buffer = buffer.match(runLengthRegex)
  ) {
    let [, count = 1, char, rest = ""] = buffer;
    buffer = rest;
    for (let i = 0; i < count; i++) result += char;
  }

  return result;
};
