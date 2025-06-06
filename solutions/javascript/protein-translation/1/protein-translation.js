const codonProteinMapping = {
  AUG: "Methionine",
  UUU: "Phenylalanine",
  UUC: "Phenylalanine",
  UUA: "Leucine",
  UUG: "Leucine",
  UCU: "Serine",
  UCC: "Serine",
  UCA: "Serine",
  UCG: "Serine",
  UAU: "Tyrosine",
  UAC: "Tyrosine",
  UGU: "Cysteine",
  UGC: "Cysteine",
  UGG: "Tryptophan",
  UAA: "STOP",
  UAG: "STOP",
  UGA: "STOP",
};

export const translate = (codonString) => {
  if (!codonString) return [];

  const codons = [];
  for (let i = 0; i < codonString.length; i += 3) {
    let codon = codonString.substring(i, i + 3);
    if (codonProteinMapping[codon] == "STOP") break;
    if (!codonProteinMapping[codon]) throw new Error("Invalid codon");
    codons.push(codonString.substring(i, i + 3));
  }

  return codons.map((codon) => codonProteinMapping[codon]);
};
