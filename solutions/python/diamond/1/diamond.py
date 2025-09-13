from itertools import chain

def rows(letter):
    letter_count = (ord(letter) - ord('A')) + 1
    width = 2 * letter_count - 1
    result = []
    for i in chain(range(letter_count), range(letter_count - 2, -1, -1)):
        letter = chr(ord('A') + i)
        row = letter.center(width, " ") if i == 0 else f"{letter}{' ' * (i * 2 - 1)}{letter}"
        result.append(row.center(width, " "))
    return result
