def sum_of_multiples(level: int, magical_items: list[int]) -> int:
    return sum({multiple for item in magical_items if item != 0 for multiple in range(item, level, item)})