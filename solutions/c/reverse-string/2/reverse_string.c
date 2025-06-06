#include "reverse_string.h"

#include <stdlib.h>
#include <string.h>

///
/// @brief Reverse a null-terminated string
/// @param value - input string to reverse. Not modified.
///
/// @returns Reversed string in heap allocated buffer that must be freed by the caller
///          or NULL if heap allocation failed
///
char* reverse(const char value[static 1])
{
    size_t len = strlen(value);
    char* result = malloc(len + 1);
    if (result == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < len; ++i)
    {
        result[len - 1 - i] = value[i];
    }
    result[len] = '\0';

    return result;
}
