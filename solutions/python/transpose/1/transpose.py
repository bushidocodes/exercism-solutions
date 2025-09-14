from itertools import zip_longest

def transpose(text):
    result = [[*line] for line in text.splitlines()]
    result = ["".join(thing) for thing in zip_longest(*result, fillvalue="$")]

    # This line is key. The right padding is erased and the left padding is
    # turned into spaces
    result = [line.rstrip("$").replace("$", " ") for line in result]
        
    return "\n".join(result)