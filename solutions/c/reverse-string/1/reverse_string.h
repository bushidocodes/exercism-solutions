#pragma once

#include <stddef.h>

typedef struct reverse_allocator_t{
    void* (*alloc)(size_t size);
    void (*free)(void* buf);
} reverse_allocator_t;

// To enable custom allocator
char *reverse_with_allocator(const char* value, const struct reverse_allocator_t* allocator);
void reverse_free(char* value, const struct reverse_allocator_t* allocator);

///
/// @brief Reverse a null-terminated string
/// @param value - input string to reverse. Not modified.
///
/// @returns Reversed string in heap allocated buffer that must be freed by the caller
///          or NULL if heap allocation failed
///
static inline char *reverse(const char* value)
{
    return reverse_with_allocator(value, NULL);
}