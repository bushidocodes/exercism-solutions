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

class ToleranceColorCode(Enum):
    GREY   =  " ±0.05%"
    VIOLET =  " ±0.1%"
    BLUE   =  " ±0.25%"
    GREEN  =  " ±0.5%"
    BROWN  =  " ±1%"
    RED    =  " ±2%"
    GOLD   =  " ±5%"
    SILVER = " ±10%"


def _digits(colors: list[str]) -> int:
    try:
        return sum(ColorCode[color.upper()].value * (10 ** i) for i, color in enumerate(reversed(colors)))
    except KeyError as e:
        raise ValueError(f"Unknown color in: {colors}") from e

def _multiplier(color: str) -> int:
    try:
        return 10 ** ColorCode[color.upper()].value
    except KeyError as e:
        raise ValueError(f"Unknown multiplier color: {color}") from e


def resistor_label(colors):
    """
    Expects: [digit_colors..., multiplier_color?, tolerance_color?]
    Returns: human-readable resistance label, e.g., '4.7 kiloohms ±5%'
    """
    resistance = 0
    tolerance = ""
    if len(colors) <= 2:
        resistance = _digits(colors)
    elif len(colors) == 3:
        resistance = _digits(colors[0:2]) * _multiplier(colors[2])
    else:
        print(colors[-2])
        resistance = _digits(colors[0:-2]) * _multiplier(colors[-2])
        try:
            tolerance = ToleranceColorCode[colors[-1].strip().upper()].value
        except KeyError as e:
            raise ValueError(f"Unknown tolerance color: {colors[-1]!r}") from e


    match resistance:
        case i if 0 <= i < 1_000: 
            return f"{i} ohms{tolerance}"
        case i if 1_000 <= i < 1_000_000: 
            return f"{int(i / 1_000) if i % 1_000 == 0 else i / 1_000} kiloohms{tolerance}"
        case i if 1_000_000 <= i < 1_000_000_000: 
            return f"{int(i / 1_000_000) if i % 1_000_000 == 0 else i / 1_000_000} megaohms{tolerance}"
        case i if 1_000_000_000 <= i < 1_000_000_000_000: 
            return f"{int(i / 1_000_000_000) if i % 1_000_000_000 == 0 else i / 1_000_000_000} gigaohms{tolerance}"
        case _:
            raise ValueError(f"Unexpected value{resistance}")
