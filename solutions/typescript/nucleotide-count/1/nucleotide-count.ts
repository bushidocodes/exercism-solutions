type NucleotideCount = {
  A: number;
  C: number;
  G: number;
  T: number;
}

export function nucleotideCounts(strand: string): NucleotideCount {
  const count: NucleotideCount = {
    "A": 0,
    "C": 0,
    "G": 0,
    "T": 0
  };

  for (let nucleotide of strand){
    switch(nucleotide){
      case "A":
        count["A"]++;
        break;
      case "C":
        count["C"]++;
        break;
      case "G":
        count["G"]++;
        break;
      case "T":
        count["T"]++;
        break;
      default:
        throw new Error('Invalid nucleotide in strand');
    }
  }
  
  return count;
}
