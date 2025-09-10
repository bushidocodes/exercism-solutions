vowels = {'a', 'e', 'i', 'o', 'u'}

def translate_single_word(text):
    if text[0:3] in {"thr", "sch"}:
        return text[3:] + text[0:3] + "ay"
    elif text[1:3] == "qu" and text[0].isalpha() and text[0] not in vowels:
        return text[3:] + text[0:3] + "ay"
    elif text[0:2] in {"ch", "qu", "th", "rh"}:
        return text[2:] + text[0:2] + "ay"
    elif text[0:2] in {"xr", "yt"} or text[0] in vowels:
        return text + "ay"
    else:
        return text[1:] + text[0] + "ay"

def translate(text):
    return " ".join(translate_single_word(word) for word in text.split(" "))
