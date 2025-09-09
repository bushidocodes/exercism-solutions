
def _mapper(dna: str) -> str:
    match dna:
        case "C":
            return "G"
        case "G":
            return "C"
        case "T":
            return "A"
        case "A":
            return "U"
        case _:
            raise ValueError(f"Invalid DNA base: {dna}")

def to_rna(dna_strand: str) -> str:
    """
    Transcribe a DNA strand into its RNA complement.
    
    Mapping:
      C → G
      G → C
      T → A
      A → U

    Raises:
        ValueError: If an invalid DNA base is encountered.
    """
    return "".join(_mapper(c.upper()) for c in dna_strand)
