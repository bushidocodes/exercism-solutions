#include "diamond.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void make_diamond_row(const char c, char **row, int row_size)
{
    char buffer[row_size];
    int center_spaces = c == 'A' ? 0 : 2 * (c - 'A') - 1;
    int leading_trailing_spaces = center_spaces > 0 ? (row_size - center_spaces - 2) / 2 : (row_size - 1) / 2;

    int i = 0;

    // Leading Spaces
    for (int j = 0; j < leading_trailing_spaces; j++)
        buffer[i++] = ' ';

    // First Character
    buffer[i++] = c;

    // If anything but 'A', center spaces and second character
    if (center_spaces > 0)
    {
        for (int j = 0; j < center_spaces; j++)
            buffer[i++] = ' ';
        buffer[i++] = c;
    }

    // Trailing Spaces
    for (int j = 0; j < leading_trailing_spaces; j++)
        buffer[i++] = ' ';
    buffer[i++] = '\0';
    *row = calloc(row_size, sizeof(char));
    strncpy(*row, buffer, row_size);
}

// Unapologetically ASCII / UTF-8
char **make_diamond(const char letter)
{
    // Heights and widths are identical, but rows need an extra space for \0
    int diamond_row_count = 2 * (letter - 'A') + 1;
    int diamond_row_size = diamond_row_count + 1;

    char **diamond = calloc(diamond_row_count, sizeof(char **));
    int diamond_row = 0;

    for (char c = 'A'; c <= letter && diamond_row < diamond_row_count; c++, diamond_row++)
        make_diamond_row(c, &diamond[diamond_row], diamond_row_size);

    for (char c = letter - 1; c >= 'A' && diamond_row < diamond_row_count; c--, diamond_row++)
        make_diamond_row(c, &diamond[diamond_row], diamond_row_size);

    return diamond;
}