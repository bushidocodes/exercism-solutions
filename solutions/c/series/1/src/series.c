#include "series.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

series_results_t series(char *input_text, unsigned int substring_length)
{
    size_t input_length = strlen(input_text);
    bool is_valid = substring_length > 0 && substring_length <= input_length;

    // TODO: There's a memory leak here?
    series_results_t result = {
        .substring_count = is_valid ? input_length - (substring_length - 1) : 0,
        .substring = calloc(sizeof(char *), result.substring_count)};

    if (result.substring == NULL)
        exit(EXIT_FAILURE);

    for (size_t i = 0; i < result.substring_count; i++)
    {
        result.substring[i] = calloc(sizeof(char), substring_length + 1);
        if (result.substring[i] == NULL)
            exit(EXIT_FAILURE);
        strncpy(result.substring[i], &input_text[i], substring_length);
    }

    return result;
}