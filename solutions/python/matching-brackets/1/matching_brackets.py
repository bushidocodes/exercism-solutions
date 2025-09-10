closing = {'{': '}', '[': ']', '(': ')'}

def is_paired(input_string: str) -> bool:
    stack = []
    for c in input_string:
        match c:
            case '[' | '(' | '{':
                stack.append(c)
            case ']' | ')' | '}':
                if len(stack) == 0 or c != closing[stack.pop()]:
                    return False
    return len(stack) == 0