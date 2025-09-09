from enum import Enum

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

def color_code(color: str) -> int:
    try:
        return ColorCode[color.upper()].value
    except KeyError:
        raise ValueError(f"Invalid color: {color!r}")

def colors() -> list[str]:
    return [c.name.lower() for c in ColorCode]
