def is_armstrong_number(number: int) -> bool:
    """
    Check if a number is an Armstrong number.
    An Armstrong number is equal to the sum of its digits
    raised to the power of the number of digits.
    """
    s = str(number)
    power = len(s)
    return number == sum(int(ch) ** power for ch in s)