export class NucleotideCounts {
  static parse(dna) {
    let nucleotides = dna.split("");

    if (nucleotides.some((e) => !/[ACGT]/.test(e)))
      throw new Error("Invalid nucleotide in strand");

    const counts = {
      A: 0,
      C: 0,
      G: 0,
      T: 0,
    };

    nucleotides.forEach((e) => counts[e]++);

    return `${counts["A"] || 0} ${counts["C"] || 0} ${counts["G"]} ${
      counts["T"]
    }`;
  }
}
