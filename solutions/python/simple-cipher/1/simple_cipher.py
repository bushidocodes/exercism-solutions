import random
import string
from itertools import islice, cycle


class Cipher:
    """
    A simple substitution cipher with a repeating key.

    >>> c = Cipher("abc")
    >>> encoded = c.encode("hello")
    >>> encoded
    'hfnlp'
    >>> c.decode(encoded)
    'hello'
    """

    ENCODE, DECODE = 1, -1

    def __init__(self, key: str | None = None) -> None:
        # Randomize a key of 100 lowercase letters if no key is provided
        if key is None:
            self.key = "".join(random.choices(string.ascii_lowercase, k=100))
        else:
            if not key.isalpha() or not key.islower():
                raise ValueError(
                    f"Invalid key '{key}': must contain only lowercase letters a–z"
                )
            self.key = key

    def _translate(self, text: str, direction: int) -> str:
        if not text.islower():
            raise ValueError(
                f"Invalid text '{text}': must contain only lowercase letters a–z"
            )
        key = "".join(islice(cycle(self.key), len(text)))
        a_code = ord("a")
        return "".join(
            chr(a_code + ((ord(t) - a_code) + direction * (ord(k) - a_code)) % 26)
            for t, k in zip(text, key)
        )

    def encode(self, text: str) -> str:
        return self._translate(text, self.ENCODE)

    def decode(self, text: str) -> str:
        return self._translate(text, self.DECODE)
