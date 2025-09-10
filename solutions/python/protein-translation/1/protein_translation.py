def proteins(strand):
    result = []
    for i in range(0, len(strand), 3):
        codon = strand[i:i+3]
        if codon in {"AUG"}:
            result.append("Methionine")
        elif codon in {"UUU", "UUC"}:
            result.append("Phenylalanine")
        elif codon in {"UUA", "UUG"}:
            result.append("Leucine")
        elif codon in {"UCU", "UCC", "UCA", "UCG"}:
            result.append("Serine")
        elif codon in {"UAU", "UAC"}:
            result.append("Tyrosine")
        elif codon in {"UGU", "UGC"}:
            result.append("Cysteine")
        elif codon in {"UGG"}:
            result.append("Tryptophan")
        elif codon in {"UAA", "UAG", "UGA"}:
            break

    return result
