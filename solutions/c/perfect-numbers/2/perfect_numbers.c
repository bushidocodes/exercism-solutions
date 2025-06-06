#include "perfect_numbers.h"

kind classify_number(int source) {
	if (source <= 0) return ERROR;

	int sum = 0;
	for (int i = 1; i <= source / 2; i++)
		if (source % i == 0) sum += i;

	if (sum == source)
		return PERFECT_NUMBER;
	else if (sum > source)
		return ABUNDANT_NUMBER;
	else if (sum < source)
		return DEFICIENT_NUMBER;
	else
		return ERROR;
}