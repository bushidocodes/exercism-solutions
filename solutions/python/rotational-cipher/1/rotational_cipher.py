def _mapper(c: str, key: int) -> str:
    if c.isupper():
        return chr(((ord(c) - ord("A") + key) % 26) + ord("A"))
    if c.islower():
        return chr(((ord(c) - ord("a") + key) % 26) + ord("a"))
    return c

def rotate(text: str, key: int) -> str:
    return "".join(_mapper(c, key) for c in text)
    
