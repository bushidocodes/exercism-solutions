#include "reverse_string.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

static reverse_allocator_t default_allocator = {
    .alloc = malloc,
    .free = free
};

char* reverse_with_allocator(const char* value, const reverse_allocator_t* allocator)
{
    assert(value != NULL);

    if (allocator == NULL)
    {
        allocator = &default_allocator;
    }

    // Consider using strnlen if available
    // Does not seem to be present here
    size_t len = strlen(value);
    char* result = allocator->alloc(len * sizeof(char));    
    if (result == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < len; ++i)
    {
        result[len - 1 - i] = value[i];
    }

    return result;
}

void reverse_free(char* value, const reverse_allocator_t* allocator)
{
    assert(value != NULL);

    if (allocator == NULL)
    {
        allocator = &default_allocator;
    }

    allocator->free(value);    
}