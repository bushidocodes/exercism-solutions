def decode(string):
    count = 0
    result = []
    for char in string:
        if char.isdigit():
            count = (count * 10) + int(char)
        else:
            result.append(char * (count or 1))
            count = 0
    return "".join(result)


def encode(string):
    last = None
    count = 0
    result = []
    for char in string:
        if char != last:
            if last is not None:
                result += f"{str(count) if count > 1 else ''}{last}"
            last = char
            count = 1
        else:
            count += 1
    if last is not None:
        result.append(f"{ str(count) if count > 1 else ''}{last}")
    return "".join(result)
