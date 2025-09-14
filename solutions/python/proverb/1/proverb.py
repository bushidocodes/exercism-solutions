def proverb(*input_data, qualifier):
    result = []

    if len(input_data) > 1:
        for (first, second) in list(zip(input_data, input_data[1:])):
            result.append(f"For want of a {first} the {second} was lost.")

    if len(input_data) > 0:
        qualified = f"{qualifier} {input_data[0]}" if qualifier else input_data[0]
        result.append(f"And all for the want of a {qualified}.")

    return result
