#include "binary_search.h"

int *binary_search(int value, const int *arr, size_t length) {
	if (length == 0) return NULL;

	int middle = length / 2;
	if (value == *(arr + middle))
		return (int *)(arr + middle);
	else if (middle == 0)
		return NULL;
	else if (value < *(arr + middle))
		return binary_search(value, arr, middle);
	else if (value > *(arr + middle))
		return binary_search(value, arr + middle, length - middle);
	return NULL;
}
