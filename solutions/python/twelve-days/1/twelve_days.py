day = [
    None,
    "first",
    "second",
    "third",
    "fourth",
    "fifth",
    "sixth",
    "seventh",
    "eighth",
    "ninth",
    "tenth",
    "eleventh",
    "twelfth"
]

gifts = [
    None,
    "a Partridge in a Pear Tree",
    "two Turtle Doves",
    "three French Hens",
    "four Calling Birds",
    "five Gold Rings",
    "six Geese-a-Laying",
    "seven Swans-a-Swimming",
    "eight Maids-a-Milking",
    "nine Ladies Dancing",
    "ten Lords-a-Leaping",
    "eleven Pipers Piping",
    "twelve Drummers Drumming"
]

def recite(start_verse: int, end_verse: int) -> list[str]:
    result = []
    for i in range(start_verse, end_verse + 1):
        match i:
            case 1:
                result.append(f"On the {day[i]} day of Christmas my true love gave to me: {gifts[i]}.")
            case i if 2 <= i <= 12:
                result.append(f"On the {day[i]} day of Christmas my true love gave to me: {', '.join(gifts[i:1:-1])}, and {gifts[1]}.")
    return result
