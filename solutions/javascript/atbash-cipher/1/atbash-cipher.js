export const transpose = (text) => {
  return text
    .split("")
    .filter((c) => /[^., ]/.test(c))
    .map((c) => c.toLowerCase())
    .map((c, i) => {
      let base = "";
      if (/[a-z]/.test(c))
        return base.concat(
          String.fromCharCode(
            "z".charCodeAt(0) - (c.charCodeAt(0) - "a".charCodeAt(0))
          )
        );
      else return base.concat(c);
    })
    .join("");
};

export const encode = (text) => {
  return transpose(text)
    .split("")
    .map((c, i) => {
      let base = i > 0 && i % 5 == 0 ? " " : "";
      return base + c;
    })
    .join("");
};

export const decode = (text) => {
  return transpose(text);
};
