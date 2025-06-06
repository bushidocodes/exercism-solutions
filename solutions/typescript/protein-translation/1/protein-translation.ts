type Protein = "Methionine" | "Phenylalanine" | "Leucine" | "Serine" | "Tyrosine" | "Cysteine" | "Tryptophan" | "STOP";

const CodonToProtein: Record<string, Protein> = {
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
}

export function translate(rna: string) {
  if (rna.length % 3 !== 0) throw new Error("Invalid rna");

  let codons: string[] = [];
  for (let i = 0; i < rna.length; i += 3){
    codons.push(rna.substring(i, i + 3))
  }

  let proteins: Protein[] = codons.map(codon => CodonToProtein[codon]);

  let stopIdx = proteins.findIndex(protein => protein === "STOP");

  return stopIdx === -1 ? proteins : proteins.slice(0, stopIdx);
}
