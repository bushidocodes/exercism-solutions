#include "sublist.h"

#include <stdbool.h>
#include <string.h>

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count) {
	// Handle Degenerate Cases of Empty Lists
	if (list_to_compare_element_count == 0 && base_list_element_count > 0)
		return SUBLIST;

	if (base_list_element_count == 0 && list_to_compare_element_count > 0)
		return SUPERLIST;

	bool base_is_larger = true;

	// If they are equal, we can just compare with memcmp
	if (list_to_compare_element_count == base_list_element_count) {
		if (memcmp(list_to_compare, base_list,
		           sizeof(int) * list_to_compare_element_count) == 0)
			return EQUAL;
		else
			return UNEQUAL;
	} else {
		base_is_larger =
		    list_to_compare_element_count < base_list_element_count;
	}

	size_t larger_count = base_is_larger ? base_list_element_count
	                                     : list_to_compare_element_count;
	int *larger = base_is_larger ? base_list : list_to_compare;
	size_t smaller_count = base_is_larger ? list_to_compare_element_count
	                                      : base_list_element_count;
	int *smaller = base_is_larger ? list_to_compare : base_list;

	for (size_t s = 0, l = 0; l < larger_count; l++) {
		if (larger[l] == smaller[s]) {
			if (s == smaller_count - 1)
				return base_is_larger ? SUBLIST : SUPERLIST;
			else
				s++;
		} else if (s > 0) {
			// Backtrack is case of failed partial match
			l -= s;
			s = 0;
		}
	}

	return UNEQUAL;
}