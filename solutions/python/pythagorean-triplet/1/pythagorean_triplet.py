# def triplets_with_sum(number: int) -> list[list[int]]:
#     result = []
#     for c in range(number // 2, 2, -1):
#         c_squared = c * c
#         for b in range(c - 1, 1, -1):
#             a = number - b - c
#             if a >= b:  # ensures a < b < c
#                 continue
#             if (a*a + b*b == c_squared):
#                 result.append([a,b,c])
#     return result
                
def triplets_with_sum(s: int) -> list[list[int]]:
    result = []
    for a in range(1, s // 3 + 1):
        numerator = s * s - 2 * s * a
        denominator = 2 * (s - a)
        if numerator % denominator == 0:
            b = numerator // denominator
            c = s - a - b
            if a < b < c:
                result.append([a, b, c])
    return result