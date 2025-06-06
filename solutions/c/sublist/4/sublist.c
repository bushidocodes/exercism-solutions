#include "sublist.h"

#include <stdbool.h>
#include <string.h>

comparison_result_t check_lists (
    const int lhs[], 
    const int rhs[],
    size_t lhs_size,
    size_t rhs_size
) {
    // Handle Degenerate Cases of Empty Lists
	if (lhs_size == 0 && rhs_size > 0) {
		return SUBLIST;
    }
	if (lhs_size > 0 && rhs_size == 0) {
		return SUPERLIST;
    }

	// If they are equal, we can just compare with memcmp
	if (lhs_size == rhs_size) {
        size_t list_size = sizeof(int) * lhs_size;
        bool is_equal = memcmp(lhs, rhs, list_size) == 0;
        return is_equal ? EQUAL : UNEQUAL;
	}

    bool rhs_is_larger = lhs_size < rhs_size;
	const int *const larger = !rhs_is_larger ? lhs : rhs;
	size_t larger_size = !rhs_is_larger ? lhs_size : rhs_size;
	const int *const smaller = rhs_is_larger ? lhs : rhs;
	size_t smaller_size = rhs_is_larger ? lhs_size : rhs_size;

    size_t smaller_idx = 0;
	for (size_t larger_idx = 0; larger_idx < larger_size - (smaller_size - 1 - smaller_idx); ++larger_idx) {
		if (larger[larger_idx] == smaller[smaller_idx]) {
			if (smaller_idx == smaller_size - 1) {
				return rhs_is_larger ? SUBLIST : SUPERLIST;
            }
			smaller_idx++;
		} else if (smaller_idx > 0) {
			// Backtrack is case of failed partial match
			larger_idx -= smaller_idx;
			smaller_idx = 0;
		}
	}

	return UNEQUAL;
}