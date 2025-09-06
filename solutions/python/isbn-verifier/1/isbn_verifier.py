def is_valid(isbn):
    digits = [x for x in isbn if x != '-']

    if len(digits) != 10:
        return False

    if any(not c.isdigit() for c in digits[:9]):
        return False

    if not (digits[9].isdigit() or digits[9] == 'X'):
        return False

    digits = [10 if x == 'X' else int(x) for x in digits]
    
    return sum(v * (10 - i) for i, v in enumerate(digits)) % 11 == 0
