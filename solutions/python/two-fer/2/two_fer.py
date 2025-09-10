def two_fer(name: str = "you") -> str:
    """
    Return a string following the 'two-fer' phrase pattern.

    If a name is provided, returns "One for <name>, one for me."
    If no name is given, defaults to "you".

    Args:
        name: The name to include in the phrase. Defaults to "you".

    Returns:
        A string in the format "One for <name>, one for me."
    """
    return f"One for {name}, one for me."
