import re

def count_words(sentence):
    word_count = {}
    for word in re.split(r"[^A-Za-z0-9']+", sentence):
        word = re.sub(r"^\'+|\'+$", "", word)
        if word:
            word_count.setdefault(word.casefold(), 0)
            word_count[word.casefold()] += 1

    return word_count
    