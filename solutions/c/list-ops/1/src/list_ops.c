#include "list_ops.h"
#include <string.h>
#include <stdio.h>

// constructs a new list
list_t *new_list(size_t length, list_value_t values[])
{
    list_t *new = malloc(sizeof(list_t) + sizeof(list_value_t) * length);
    if (values != NULL)
        memcpy(&(new->values), values, sizeof(list_value_t) * length);
    new->length = length;
    return new;
}

// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2)
{
    size_t combined_length = list1->length + list2->length;
    list_value_t combined_values[combined_length];
    if (list1->length > 0)
        memcpy(&combined_values[0], &list1->values[0], sizeof(list_value_t) * list1->length);
    if (list2->length > 0)
        memcpy(&combined_values[list1->length], &list2->values[0], sizeof(list_value_t) * list2->length);

    return new_list(combined_length, combined_values);
}

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_value_t value))
{
    list_t *buffer = new_list(list->length, list->values);
    for (size_t i = 0; i < buffer->length; i++)
    {
        if (!filter(buffer->values[i]))
        {
            // Shift values left to fill the hole
            if (i + 1 < buffer->length)
                memmove(&buffer->values[i], &buffer->values[i + 1], sizeof(list_value_t) * (buffer->length - 1 - i));
            buffer->length--;
        }
    }

    // Release the memory we don't need
    if (buffer->length < list->length)
        buffer = realloc(buffer, sizeof(list_t) + buffer->length * sizeof(list_value_t));

    return buffer;
}

// returns the length of the list
size_t length_list(list_t *list)
{
    return list->length;
}

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_value_t (*map)(list_value_t value))
{
    list_t *buffer = new_list(list->length, list->values);
    for (size_t i = 0; i < buffer->length; i++)
    {
        list_value_t result = map(buffer->values[i]);
        memmove(&buffer->values[i], &result, sizeof(list_value_t));
    }
    return buffer;
}

// folds (reduces) the given list from the left with a function
list_value_t foldl_list(list_t *list, list_value_t initial,
                        list_value_t (*foldl)(list_value_t value,
                                              list_value_t initial))
{
    list_value_t accumulator = initial;
    for (size_t i = 0; i < list->length; i++)
        accumulator = foldl(list->values[i], accumulator);
    return accumulator;
}

// folds (reduces) the given list from the right with a function
list_value_t foldr_list(list_t *list, list_value_t initial,
                        list_value_t (*foldr)(list_value_t value,
                                              list_value_t initial))
{
    list_value_t accumulator = initial;
    for (size_t i = list->length; i > 0; i--)
        accumulator = foldr(list->values[i - 1], accumulator);
    return accumulator;
}

// reverse the elements of the list
list_t *reverse_list(list_t *list)
{
    list_t *buffer = new_list(list->length, list->values);
    for (size_t i = 0; i < buffer->length; i++)
        memcpy(&buffer->values[i], &list->values[list->length - 1 - i], sizeof(list_value_t));
    return buffer;
}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list)
{
    free(list);
}
