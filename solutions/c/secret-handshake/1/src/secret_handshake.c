#include "secret_handshake.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char *copy_string(const char *str)
{
    size_t len = strlen(str);
    char *copy = malloc(len + 1);
    if (copy)
        strcpy(copy, str);
    return copy;
}

const char **commands(size_t number)
{
    const char **result = calloc(100, sizeof(char *));
    uint16_t result_length = 0;

    bool reverse = (number & 16) == 16;

    if (reverse)
    {
        if ((number & 8) == 8)
            result[result_length++] = copy_string("jump");
        if ((number & 4) == 4)
            result[result_length++] = copy_string("close your eyes");
        if ((number & 2) == 2)
            result[result_length++] = copy_string("double blink");
        if ((number & 1) == 1)
            result[result_length++] = copy_string("wink");
    }
    else
    {
        if ((number & 1) == 1)
            result[result_length++] = copy_string("wink");
        if ((number & 2) == 2)
            result[result_length++] = copy_string("double blink");
        if ((number & 4) == 4)
            result[result_length++] = copy_string("close your eyes");
        if ((number & 8) == 8)
            result[result_length++] = copy_string("jump");
    }

    return result;
}