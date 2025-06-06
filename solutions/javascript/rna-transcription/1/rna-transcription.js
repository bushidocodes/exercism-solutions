export const toRna = (dna) => {
  return dna
    .split("")
    .map((c) => {
      switch (c) {
        case "C":
          return "G";
        case "G":
          return "C";
        case "T":
          return "A";
        case "A":
          return "U";
      }
    })
    .join("");
};
