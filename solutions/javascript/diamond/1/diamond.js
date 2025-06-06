const aCC = "A".charCodeAt(0);

const generateRow = (charCode, target) => {
  const row = [];
  const outerGap = target.charCodeAt(0) - charCode;

  for (let i = 0; i < outerGap; i++) row.push(" ");
  row.push(String.fromCharCode(charCode));

  if (charCode > aCC) {
    for (let i = 0; i < 2 * (charCode - aCC) - 1; i++) row.push(" ");
    row.push(String.fromCharCode(charCode));
  }

  for (let i = 0; i < outerGap; i++) row.push(" ");

  return row.join("");
};

export const rows = (target) => {
  const result = [];

  for (let charCode = aCC; charCode <= target.charCodeAt(0); charCode++)
    result.push(generateRow(charCode, target));
  for (let charCode = target.charCodeAt(0) - 1; charCode >= aCC; charCode--)
    result.push(generateRow(charCode, target));

  return result;
};
