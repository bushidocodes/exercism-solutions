def find(search_list: list[int], value: int) -> int:
    if (len(search_list) == 0):
        raise ValueError("value not in array")

    lhs, rhs = 0, len(search_list) - 1

    while lhs <= rhs:
        mid = lhs + (rhs - lhs) // 2
        value_at_mid = search_list[mid]
        if (value == value_at_mid):
            return mid
        elif value < value_at_mid:
            rhs = mid - 1
        elif value > value_at_mid:
            lhs = mid + 1
    
    raise ValueError("value not in array")
