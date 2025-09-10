def distance(strand_a: str, strand_b: str) -> int:
    """Return the Hamming distance between two DNA strands."""
    if len(strand_a) != len(strand_b):
        raise ValueError("Strands must be of equal length.")
    return sum(first != second for first, second in zip(strand_a, strand_b))
