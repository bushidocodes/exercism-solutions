def recite(start: int, take: int = 1):
    numbers = [
        None,
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
    ]

    result: list[str] = []

    for verse in range(start, start - take, -1):
        match verse:
            case 1:
                result.append(
                    f"{numbers[1].capitalize()} green bottle hanging on the wall,"
                )
                result.append(
                    f"{numbers[1].capitalize()} green bottle hanging on the wall,"
                )
                result.append("And if one green bottle should accidentally fall,")
                result.append("There'll be no green bottles hanging on the wall.")
                result.append("")
            case v if 2 <= v <= 10:
                result.append(
                    f"{numbers[v].capitalize()} green bottles hanging on the wall,"
                )
                result.append(
                    f"{numbers[v].capitalize()} green bottles hanging on the wall,"
                )
                result.append("And if one green bottle should accidentally fall,")
                result.append(
                    f"There'll be {numbers[v - 1]} green bottle{'s' if v - 1 != 1 else ''} hanging on the wall."
                )
                result.append("")
            case _:
                raise ValueError(
                    f"Verses must be between 1 and 10, tried to recite {verse}"
                )

    if result and result[-1] == "":
        result.pop()
    return result
