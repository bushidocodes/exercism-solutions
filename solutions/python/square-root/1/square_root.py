
lookup = {}
max = 5
for i in range(max + 1):
    lookup[i ** 2] = i

def square_root(number):
    try:
        if number > max:
            for i in range(max + 1, number + 1):
                lookup[i ** 2] = i
        return lookup[number]
    except KeyError:
        raise ValueError("input out of range")  