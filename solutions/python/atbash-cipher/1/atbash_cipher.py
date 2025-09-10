def _atbash_char(char: str) -> str:
    if char.isalpha():
        return chr(ord('z') - (ord(char.lower()) - ord('a')))
    elif char.isdigit():
        return char
    else:
        return ""

def _atbash_str(text: str) -> str:
    return "".join(_atbash_char(char) for char in text if char.isalnum())

def encode(plain_text: str) -> str:
    result = _atbash_str(plain_text)
    return " ".join([result[i:i+5] for i in range(0, len(result), 5)])

def decode(ciphered_text: str) -> str:
    return _atbash_str(ciphered_text)
