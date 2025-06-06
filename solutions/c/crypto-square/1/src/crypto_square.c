#include "crypto_square.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *ciphertext(const char *input)
{
    size_t input_length = strlen(input);
    char *buffer = calloc(input_length, sizeof(char));
    size_t buffer_length = 0;

    // Normalize Input
    for (size_t i = 0; i < input_length; i++)
        if (isalnum(input[i]))
            buffer[buffer_length++] = tolower(input[i]);

    // Calculate Columns and Rows
    int columns = ceil(sqrt(buffer_length));
    int rows;
    if ((columns * (columns - 1)) > (int)buffer_length)
        rows = columns - 1;
    else
        rows = columns;

    // Square with an additional "column" of delimiters
    char *result = calloc(rows * columns + columns + 1, sizeof(char));
    size_t result_length = 0;

    for (int c = 0; c < columns; c++)
    {
        for (int r = 0; r < rows; r++)
        {
            // We might have to pad the string to get a square
            char current;
            if (r * columns + c < (int)buffer_length)
                current = buffer[r * columns + c];
            else
                current = ' ';

            result[result_length++] = current;
        }
        // Add additional space to delimit rows
        if (c + 1 < columns)
            result[result_length++] = ' ';
    }

    result[result_length++] = '\0';

    free(buffer);
    return result;
}