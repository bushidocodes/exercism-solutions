def is_isogram(string: str) -> bool:
    seen = set()
    for c in string.casefold():
        if c.isalpha():
            if c in seen:
                return False
            seen.add(c)
    return True
