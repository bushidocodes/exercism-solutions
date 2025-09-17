import math


def cipher_text(plain_text):
    # Remove spaces and convert to lowercase
    normalized = "".join(filter(str.isalnum, plain_text)).lower()
    if not normalized:
        return ""

    length = len(normalized)

    # Determine dimensions of square
    cols = math.ceil(math.sqrt(length))
    rows = math.ceil(length / cols)

    # Populate Square
    padded = normalized.ljust(rows * cols)
    chunks = [padded[i::cols] for i in range(cols)]

    return " ".join(chunks)
