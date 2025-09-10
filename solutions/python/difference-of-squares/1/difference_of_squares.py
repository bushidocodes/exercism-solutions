def square_of_sum(number: int) -> int:
    return sum(range(number+1)) ** 2


def sum_of_squares(number: int) -> int:
    rng = range(number+1)
    return sum(el ** 2 for el in rng)


def difference_of_squares(number: int) -> int:
    return square_of_sum(number) - sum_of_squares(number)
