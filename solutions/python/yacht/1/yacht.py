# Score categories.
# Change the values as you see fit.
YACHT = 0
ONES = 1
TWOS = 2
THREES = 3
FOURS = 4
FIVES = 5
SIXES = 6
FULL_HOUSE = 7
FOUR_OF_A_KIND = 8
LITTLE_STRAIGHT = 9
BIG_STRAIGHT = 10
CHOICE = 11

from collections import Counter


def score(dice, category):
    counts = Counter(dice)
    if category == YACHT:
        return 50 if len(set(dice)) == 1 else 0
    elif category in (ONES, TWOS, THREES, FOURS, FIVES, SIXES):
        return category * counts[category]
    elif category == FULL_HOUSE:
        if sorted(counts.values()) == [2, 3]:
            return sum(dice)
        return 0
    elif category == FOUR_OF_A_KIND:
        for num, cnt in counts.items():
            if cnt >= 4:
                return num * 4
        return 0
    elif category == LITTLE_STRAIGHT:
        return 30 if set(dice) == {1, 2, 3, 4, 5} else 0
    elif category == BIG_STRAIGHT:
        return 30 if set(dice) == {2, 3, 4, 5, 6} else 0
    elif category == CHOICE:
        return sum(dice)
    else:
        raise ValueError("Invalid category")
