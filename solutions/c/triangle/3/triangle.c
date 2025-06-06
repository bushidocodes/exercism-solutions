#include "triangle.h"

#include <stdlib.h>

static int double_comparator(const void *const a, const void *const b) {
	if (*(double*)a < *(double*)b)
		return -1;
	else if (*(double*)a == *(double*)b)
		return 0;
	else
		return 1;
}

static inline bool is_degenerate(triangle_t triangle) {
	double sides[3] = {triangle.a, triangle.b, triangle.c};
	for (int i = 0; i < 3; i++)
		if (sides[i] == 0) return true;

	qsort(sides, 3, sizeof(double), double_comparator);
	return sides[0] + sides[1] <= sides[2];
}

bool is_equilateral(triangle_t triangle) {
    if (is_degenerate(triangle)) return false;
	return triangle.a == triangle.b && triangle.b == triangle.c;
}

bool is_isosceles(triangle_t triangle) {
	if (is_degenerate(triangle)) return false;
	return (triangle.a == triangle.b || triangle.b == triangle.c ||
	        triangle.a == triangle.c);
}

bool is_scalene(triangle_t triangle) {
	if (is_degenerate(triangle)) return false;
	return triangle.a != triangle.b && triangle.b != triangle.c &&
	       triangle.a != triangle.c;
}