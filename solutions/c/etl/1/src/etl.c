#include "etl.h"
#include <ctype.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define ASCII_ALPHABET_SIZE 26

int new_map_comparator(const void *a_raw, const void *b_raw);

int new_map_comparator(const void *a_raw, const void *b_raw)
{
    new_map *a = (new_map *)a_raw;
    new_map *b = (new_map *)b_raw;
    return a->key - b->key;
}

int convert(const legacy_map *input, const size_t input_len,
            new_map **output)
{
    legacy_map *cursor = (legacy_map *)input;
    size_t buffer_capacity = ASCII_ALPHABET_SIZE;
    size_t buffer_size = 0;
    new_map buffer[buffer_capacity];

    for (size_t i = 0; i < input_len; i++)
    {
        legacy_map *current = cursor + i;
        for (size_t j = 0; j < strlen(current->keys); j++)
            if (buffer_size < buffer_capacity)
                buffer[buffer_size++] = (new_map){
                    .key = tolower(current->keys[j]),
                    .value = current->value};
    };
    qsort(&buffer, buffer_size, sizeof(new_map), new_map_comparator);
    *output = malloc(sizeof(new_map) * buffer_size);
    memcpy(*output, &buffer, buffer_size * sizeof(new_map));
    return buffer_size;
}