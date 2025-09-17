from itertools import zip_longest


def answer(question):
    if not question.startswith("What is ") or not question.endswith("?"):
        raise ValueError("syntax error")

    # Remove the leading "What is " and trailing "?"
    expression: str = question[8:-1].strip()

    # If the expression is empty, it's a syntax error
    if not expression:
        raise ValueError("syntax error")

    # Replace supported operators
    expression = (
        expression.replace("plus", "+")
        .replace("minus", "-")
        .replace("multiplied by", "*")
        .replace("divided by", "/")
    )

    tokens = expression.split()

    if not tokens or not (
        tokens[0].lstrip("-").isdigit() and (tokens[0][0] != "-" or len(tokens[0]) > 1)
    ):
        raise ValueError("syntax error")

    for token in tokens[::2]:  # Check all number positions
        if not (token.lstrip("-").isdigit() and (token[0] != "-" or len(token) > 1)):
            raise ValueError("syntax error")

    for token in tokens[1::2]:  # Check all operator positions
        if token.lstrip("-").isdigit():
            raise ValueError("syntax error")

    accumulator = int(tokens[0])

    # Sliding window of 2 elements over slice of tokens
    for op, num in zip_longest(tokens[1::2], tokens[2::2]):
        if op not in {"+", "-", "*", "/"}:
            raise ValueError("unknown operation")
        if num is None:
            raise ValueError("syntax error")
        match op:
            case "+":
                accumulator += int(num)
            case "-":
                accumulator -= int(num)
            case "*":
                accumulator *= int(num)
            case "/":
                if int(num) == 0:
                    raise ValueError("division by zero")
                accumulator //= int(num)

    return accumulator
