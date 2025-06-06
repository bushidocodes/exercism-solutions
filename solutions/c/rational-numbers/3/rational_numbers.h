#pragma once

#include <stdint.h>

typedef struct {
	int numerator;
	int denominator;
} rational_t;

rational_t add(rational_t r1, rational_t r2);
rational_t subtract(rational_t r1, rational_t r2);
rational_t multiply(rational_t r1, rational_t r2);
rational_t divide(rational_t r1, rational_t r2);
rational_t absolute(rational_t r1);
rational_t exp_rational(rational_t r1, uint16_t n);
float exp_real(uint16_t r1, rational_t n);
rational_t reduce(rational_t r1);
