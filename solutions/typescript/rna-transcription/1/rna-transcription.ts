class Transcriptor {
  private static DNA_TO_RNA: Record<string, string> = {
    C: "G",
    G: "C",
    A: "U",
    T: "A",
  };

  toRna(dnaSequence: string) {
    return dnaSequence
      .split("")
      .map((dna) => {
        const result: string = Transcriptor.DNA_TO_RNA[dna];
        if (!result) throw new Error("Invalid input DNA.");
        else return result;
      })
      .join("");
  }
}

export default Transcriptor;
