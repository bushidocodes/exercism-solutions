def not_degenerate(sides: list[int]) -> bool:
    [small, middle, large] = sorted(sides)
    return small > 0 and  large < (middle + small)

def equilateral(sides: list[int]) -> bool:
    return not_degenerate(sides) and sides[0] == sides[1] and sides[1] == sides[2]

def isosceles(sides: list[int]) -> bool:
    return not_degenerate(sides) and len(set(sides)) < 3

def scalene(sides: list[int]) -> bool:
    return not_degenerate(sides) and sides[0] != sides[1] and sides[1] != sides[2] and sides[0] != sides[2]
