def equilateral(sides):
    return sides[0] != 0 and sides[0] == sides [1] and sides [1] == sides[2]

def isosceles(sides):
    max_value = max(sides)
    rest = sum(sides) - max_value
    if (rest <= max_value):
        return False
    return (sides[0] == sides [1]) or (sides[1] == sides[2]) or (sides[2] == sides[0])

def scalene(sides):
    max_value = max(sides)
    rest = sum(sides) - max_value
    if (rest <= max_value):
        return False
    return sides[0] != 0 and sides[0] != sides [1] and sides [1] != sides[2] and sides [0] != sides[2]

