import math
from typing import Literal

def factors_excluding_self(number) -> set[int]:
    factors = set()

    if number > 1:
        factors.add(1)
        
    i = 2
    ceil = number // 2
    while i <= ceil:
        if number % i == 0:
            factors.add(i)
            factors.add(number // i)
            ceil = number // i
        i += 1
    return factors

def classify(number: int) -> Literal["perfect", "abundant", "deficient"]:
    """ A perfect number equals the sum of its positive divisors.

    :param number: int a positive integer
    :return: str the classification of the input integer
    """

    if number < 1:
        raise ValueError("Classification is only possible for positive integers.")

    aliquot_sum = sum(factors_excluding_self(number))

    if aliquot_sum == number:
        return "perfect"
    elif aliquot_sum > number:
        return "abundant"
    else:
        return "deficient"
