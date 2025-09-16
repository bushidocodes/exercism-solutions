DIGIT_WIDTH = 3
DIGIT_HEIGHT = 4

DIGIT_MAP = {
    " _ \n| |\n|_|\n   ": "0",
    "   \n  |\n  |\n   ": "1",
    " _ \n _|\n|_ \n   ": "2",
    " _ \n _|\n _|\n   ": "3",
    "   \n|_|\n  |\n   ": "4",
    " _ \n|_ \n _|\n   ": "5",
    " _ \n|_ \n|_|\n   ": "6",
    " _ \n  |\n  |\n   ": "7",
    " _ \n|_|\n|_|\n   ": "8",
    " _ \n|_|\n _|\n   ": "9",
}


def convert_digit(digit_grid: list[str]) -> str:
    """Convert a 3x4 digit block into a single character (0–9 or '?')."""
    return DIGIT_MAP.get("\n".join(digit_grid), "?")


def convert(input_grid: list[str]) -> str:
    """Convert a full OCR grid of ASCII digits into a string.

    Multiple lines of digits are separated by commas.
    """
    line_count = len(input_grid)
    col_count = len(input_grid[0]) if line_count else 0

    if line_count % DIGIT_HEIGHT != 0:
        raise ValueError("Number of input lines is not a multiple of four")
    if any(len(row) % DIGIT_WIDTH != 0 for row in input_grid):
        raise ValueError("Number of input columns is not a multiple of three")
    if any(len(row) != col_count for row in input_grid):
        raise ValueError("Input rows have inconsistent lengths")

    result = []
    for line_idx in range(0, line_count, DIGIT_HEIGHT):
        digits_row = ""
        for col_idx in range(0, col_count, DIGIT_WIDTH):
            digit_grid = [
                row[col_idx : col_idx + DIGIT_WIDTH]
                for row in input_grid[line_idx : line_idx + 4]
            ]
            digits_row += convert_digit(digit_grid)
        result.append(digits_row)

    return ",".join(result)
