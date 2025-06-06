#include "binary_search.h"

int *binary_search(int needle, const int *haystack, size_t hackstack_len) {
	if (hackstack_len == 0) return NULL;

	int mid_idx = hackstack_len / 2;
    int *mid_elem = (int *)haystack + mid_idx;
    
	if (needle == *mid_elem) return mid_elem;
	else if (mid_idx == 0) return NULL;
	else if (needle < *mid_elem) return binary_search(needle, haystack, mid_idx);
	else return binary_search(needle, mid_elem + 1, hackstack_len - mid_idx);
}
