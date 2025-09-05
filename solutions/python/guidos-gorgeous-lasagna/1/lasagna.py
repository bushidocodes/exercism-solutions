from typing import Final

EXPECTED_BAKE_TIME: Final[int] = 40
PREPARATION_TIME: Final[int] = 2


def bake_time_remaining(elapsed_bake_time: int) -> int:
    """Calculate the bake time remaining.

    :param elapsed_bake_time: int - baking time already elapsed.
    :return: int - remaining bake time (in minutes) derived from 'EXPECTED_BAKE_TIME'.

    Function that takes the actual minutes the lasagna has been in the oven as
    an argument and returns how many minutes the lasagna still needs to bake
    based on the `EXPECTED_BAKE_TIME`.
    """

    return EXPECTED_BAKE_TIME - elapsed_bake_time

def preparation_time_in_minutes(number_of_layers: int) -> int:
    """
    Return the expected preparation time

    :param number_of_layers: int - number of layers on lasagna.
    :return: int - preparation time (in minutes)
    
    """
    return PREPARATION_TIME * number_of_layers

def elapsed_time_in_minutes(number_of_layers: int, elapsed_bake_time: int) -> int:
    """
    Return the total minutes you have been in the kitchen cooking

    :param number_of_layers: int - number of layers on lasagna.
    :param elapsed_bake_time: int - baking time already elapsed.
    :return: int - total elapsed time (in minutes) include preparation and baking
    
    your preparation time layering + the time the lasagna has spent baking in the oven.
    """
    return preparation_time_in_minutes(number_of_layers) + elapsed_bake_time
