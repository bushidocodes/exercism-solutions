def say_to_nineteen(number):
    words = [
        "zero",
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
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen"
    ]
    return words[number]


def say_tens(number):
    tens_place = [None, None, "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]
    match (number):
        case n if 0 <= n <= 19:
            return say_to_nineteen(number)
        case n if n % 10 == 0:
            return tens_place[number // 10]
        case _:
            return f"{tens_place[number // 10]}-{say_to_nineteen(number % 10)}"

def say_hundreds(number):
    match (number):
        case n if 0 <= n <= 99:
            return say_tens(number)
        case n if 100 <= n <= 999 and n % 100 == 0:
            return f"{say_to_nineteen((number // 100) % 10)} hundred"
        case _:
            return f"{say_to_nineteen((number // 100) % 10)} hundred {say_tens(number % 100)}"

def say_thousands(number):
    match (number):
        case n if 0 <= n <= 999:
            return say_hundreds(number)
        case n if 1000 <= n <= 999_999 and n % 1_000 == 0:
            return f"{say_hundreds((number // 1_000) % 1000)} thousand"
        case _:
            return f"{say_hundreds((number // 1_000) % 1000)} thousand {say_hundreds(number % 1000)}"

def say_millions(number):
    match (number):
        case n if 0 <= n <= 999_999:
            return say_thousands(number)
        case n if 1_000_000 <= n <= 999_999_999 and n % 1_000_000 == 0:
            return f"{say_hundreds((number // 1_000_000) % 1000)} million"
        case _:
            return f"{say_hundreds((number // 1_000_000) % 1000)} million {say_thousands(number % 1_000_000)}"

def say_billions(number):
    match (number):
        case n if 0 <= n <= 999_999_999:
            return say_millions(number)
        case n if 1_000_000_000 <= n <= 999_999_999_999 and n % 1_000_000_000 == 0:
            return f"{say_hundreds((number // 1_000_000_000) % 1000)} billion"
        case _:
            return f"{say_hundreds((number // 1_000_000_000) % 1000)} billion {say_millions(number % 1_000_000_000)}"

def say(number):
    match (number):
        case n if 0 <= n <= 999_999_999_999:
            return say_billions(number)
        case _:
            raise ValueError("input out of range")

