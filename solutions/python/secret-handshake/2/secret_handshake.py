def commands(binary_str):
    if (len(binary_str) != 5):
        raise ValueError("binary_str must be len of 5")
    if not set(binary_str) <= {"0", "1"}:
        raise ValueError("binary_str must only contain '0' or '1'")

    actions = ["reverse", "jump", "close your eyes", "double blink", "wink"]
    
    result = [actions[i] for i in range(4, 0, -1) if binary_str[i] == "1"]   
    if (binary_str[0] == "1"):
        result.reverse()

    return result
