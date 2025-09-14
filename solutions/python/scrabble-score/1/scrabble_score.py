LETTER_SCORES = {
    **dict.fromkeys("AEIOULNRST", 1),
    **dict.fromkeys("DG", 2),
    **dict.fromkeys("BCMP", 3),
    **dict.fromkeys("FHVWY", 4),
    "K": 5,
    **dict.fromkeys("JX", 8),
    **dict.fromkeys("QZ", 10),
}
        

def score(word):
    try:
        return sum(LETTER_SCORES[letter.upper()] for letter in word)
    except KeyError:
        raise ValueError("Invalid Scrabble Character in word")