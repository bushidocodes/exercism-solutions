const aCC: number = "A".charCodeAt(0);

const generateRow = (charCode: number, targetCC: number): String => {
  const c = String.fromCharCode(charCode);
  const outerGap = targetCC - charCode;

  if (charCode == aCC){
    return `${"".padStart(outerGap, " ")}${c}${"".padStart(outerGap, " ")}\n`
  } else {
    const innerGap = 2 * (charCode - aCC) - 1;
    return `${"".padStart(outerGap, " ")}${c}${"".padStart(innerGap, " ")}${c}${"".padStart(outerGap, " ")}\n`
  }
};

export function makeDiamond(target: String): String {
  const result = [];
  const targetCC = target.charCodeAt(0);
  for (let charCode = aCC; charCode <= targetCC; charCode++)
    result.push(generateRow(charCode, targetCC));
  for (let charCode = targetCC - 1; charCode >= aCC; charCode--)
    result.push(generateRow(charCode, targetCC));
  
  return result.join("");
}
