from enum import Enum
from itertools import islice

class ColorCode(Enum):
    BLACK  = 0
    BROWN  = 1
    RED    = 2
    ORANGE = 3
    YELLOW = 4
    GREEN  = 5
    BLUE   = 6
    VIOLET = 7
    GREY   = 8
    WHITE  = 9

def value(colors: list[str]) -> int:
    first_two = list(islice(colors, 2))
    try:
        return sum(ColorCode[color.upper()].value * (10 ** i) for i, color in enumerate(reversed(first_two)))
    except KeyError as e:
        raise ValueError(f"Unknown color in: {first_two}") from e
