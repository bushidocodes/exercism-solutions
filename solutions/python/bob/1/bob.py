
def response(hey_bob: str) -> str:
    hey_bob = hey_bob.strip()
    is_silent = all(s.isspace() for s in hey_bob)
    chars = [s for s in hey_bob if s.isalpha()]
    is_yelling = len(chars) > 0 and all(s.isupper() for s in chars)
    is_question = hey_bob.endswith("?")

    if not is_yelling and is_question:
        return "Sure."

    if is_yelling and not is_question:
        return "Whoa, chill out!"

    if is_yelling and is_question:
        return "Calm down, I know what I'm doing!"

    if is_silent:
        return "Fine. Be that way!"

    return "Whatever."