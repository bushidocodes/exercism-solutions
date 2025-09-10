import re

def abbreviate(words):
    return "".join(word[0].title() for word in re.split(r"[_ -]", words) if word)