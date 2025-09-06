import string

def is_pangram(sentence):
    letters = {c.lower() for c in sentence if c.isalpha()}
    return set(string.ascii_lowercase).issubset(letters)
