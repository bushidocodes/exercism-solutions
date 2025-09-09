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

def _value(colors: list[str]) -> int:
    """
    Calculate a numeric value from color bands.
    'colors' should be 2 or 3 entries: [digit1, digit2] or [multiplier_color].
    """
    try:
        if len(colors) == 1:
            return ColorCode[colors[0].strip().upper()].value
        elif len(colors) == 2:
            d1 = ColorCode[colors[0].strip().upper()].value
            d2 = ColorCode[colors[1].strip().upper()].value
            return d1 * 10 + d2
        else:
            raise ValueError("Use only 1 (multiplier) or 2 (significant digits) colors")
    except KeyError as e:
        raise ValueError(f"Unknown color: {e.args[0]!r}") from e



def label(colors):
    """
    Expects: [digit1_color, digit2_color, multiplier_color]
    Returns: human-readable resistance label, e.g., '4 megaohms'

    Ignores extra colors!
    """
    if len(colors) < 3:
        raise ValueError(f"Expected at least 3 colors, got {len(colors)}")
        
    resistance = _value(colors[0:2]) * 10 ** (_value(colors[2:3]))

    match resistance:
        case i if 0 <= i < 1_000: 
            return f"{i} ohms"
        case i if 1_000 <= i < 1_000_000: 
            return f"{i // 1_000} kiloohms"
        case i if 1_000_000 <= i < 1_000_000_000: 
            return f"{i // 1_000_000} megaohms"
        case i if 1_000_000_000 <= i < 1_000_000_000_000: 
            return f"{i // 1_000_000_000} gigaohms"
        case _:
            raise ValueError(f"Unexpected value {resistance }")
