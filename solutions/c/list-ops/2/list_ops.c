#include "list_ops.h"

#include <stdio.h>
#include <string.h>

// constructs a new list
list_t *new_list(size_t length, list_element_t elements[]) {
	list_t *new = malloc(sizeof(list_t) + sizeof(list_element_t) * length);
	if (elements != NULL)
		memcpy(&(new->elements), elements, sizeof(list_element_t) * length);
	new->length = length;
	return new;
}

// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2) {
	size_t combined_length = list1->length + list2->length;
	list_element_t combined_values[combined_length];
	if (list1->length > 0)
		memcpy(&combined_values[0], &list1->elements[0],
		       sizeof(list_element_t) * list1->length);
	if (list2->length > 0)
		memcpy(&combined_values[list1->length], &list2->elements[0],
		       sizeof(list_element_t) * list2->length);

	return new_list(combined_length, combined_values);
}

// filter list returning only elements that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t value)) {
	list_t *buffer = new_list(list->length, list->elements);
	for (size_t i = 0; i < buffer->length; i++) {
		if (!filter(buffer->elements[i])) {
			// Shift elements left to fill the hole
			if (i + 1 < buffer->length)
				memmove(&buffer->elements[i], &buffer->elements[i + 1],
				        sizeof(list_element_t) * (buffer->length - 1 - i));
			buffer->length--;
		}
	}

	// Release the memory we don't need
	if (buffer->length < list->length)
		buffer = realloc(
		    buffer, sizeof(list_t) + buffer->length * sizeof(list_element_t));

	return buffer;
}

// returns the length of the list
size_t length_list(list_t *list) { return list->length; }

// return a list of elements whose elements equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t value)) {
	list_t *buffer = new_list(list->length, list->elements);
	for (size_t i = 0; i < buffer->length; i++) {
		list_element_t result = map(buffer->elements[i]);
		memmove(&buffer->elements[i], &result, sizeof(list_element_t));
	}
	return buffer;
}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t value,
                                                  list_element_t initial)) {
	list_element_t accumulator = initial;
	for (size_t i = 0; i < list->length; i++)
		accumulator = foldl(list->elements[i], accumulator);
	return accumulator;
}

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t value,
                                                  list_element_t initial)) {
	list_element_t accumulator = initial;
	for (size_t i = list->length; i > 0; i--)
		accumulator = foldr(list->elements[i - 1], accumulator);
	return accumulator;
}

// reverse the elements of the list
list_t *reverse_list(list_t *list) {
	list_t *buffer = new_list(list->length, list->elements);
	for (size_t i = 0; i < buffer->length; i++)
		memcpy(&buffer->elements[i], &list->elements[list->length - 1 - i],
		       sizeof(list_element_t));
	return buffer;
}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list) { free(list); }
