#include <math.h>
#include "armstrong_numbers.h"

static inline int count_digits(const int candidate) {
    int digit_count = 0;
    for (int buffer = candidate; buffer > 0; buffer /= 10) {
        digit_count++;
    }

    return digit_count;
}

static inline int sum_digits_raised_to_power_of_digit_count(const int candidate) {
    const int digit_count = count_digits(candidate);
    
    int sum = 0;
    for (int buffer = candidate; buffer > 0; buffer /= 10) {
        sum += pow(buffer % 10, digit_count);
    }

    return sum;
}

bool is_armstrong_number(const int candidate) {
    return sum_digits_raised_to_power_of_digit_count(candidate) == candidate;
}