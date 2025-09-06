from math import sqrt

def score(x: int | float, y: int | float) -> int:
    match sqrt(x ** 2 + y ** 2):
        case d if 0 <= d <= 1:
            return 10
        case d if 1 < d <= 5:
            return 5
        case d if 5 < d <= 10:
            return 1
        case _:
            return 0
