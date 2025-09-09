def find_anagrams(word, candidates):
    def bagify_letters(w: str) -> tuple[str, ...]:
        return tuple(sorted(w.casefold()))
    
    bag_of_letters = bagify_letters(word)
    return [c for c in candidates if c.casefold() != word.casefold() and bagify_letters(c) == bag_of_letters]
