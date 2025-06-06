#include <math.h>
#include "armstrong_numbers.h"

static inline int count_digits(const int source) {
    int digit_count = 0;
    for (int buffer = source; buffer > 0; buffer /= 10) {
        digit_count++;
    }

    return digit_count;
}

static inline int sum_digits_raised_to_power_of_digit_count(const int source) {
    int result = 0;
    int digit_count = count_digits(source);
    for (int buffer = source; buffer > 0; buffer /= 10) {
        result += pow(buffer % 10, digit_count);
    }

    return result;
}

int is_armstrong_number(int candidate) {
    return sum_digits_raised_to_power_of_digit_count(candidate) == candidate;
}