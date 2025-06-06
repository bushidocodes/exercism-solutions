#include "saddle_points.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

saddle_points_t *saddle_points(uint16_t row_count, uint16_t row_size, uint8_t matrix[row_count][row_size])
{
    // Allocate a buffer of candidates
    uint16_t candidates_capacity = row_count * 2;
    saddle_point_t *candidates = calloc(sizeof(saddle_point_t), candidates_capacity);
    uint16_t candidates_size = 0;

    // Keep track of the values of each candidate using matching indices
    uint8_t value[candidates_capacity];

    for (size_t y = 0; y < row_count; y++)
    {
        // Find the max value in the row
        int8_t greatest_in_row = INT8_MIN;
        for (size_t x = 0; x < row_size; x++)
            if (matrix[y][x] > greatest_in_row)
                greatest_in_row = matrix[y][x];

        // Add all cells equal to max to our buffers
        for (size_t x = 0; x < row_size; x++)
            if (matrix[y][x] == greatest_in_row)
            {
                if (candidates_size >= candidates_capacity)
                {
                    printf("Exceeded max number of candidates\n");
                    exit(EXIT_FAILURE);
                }
                value[candidates_size] = greatest_in_row;
                candidates[candidates_size++] = (saddle_point_t){
                    .column = x + 1,
                    .row = y + 1};
            }
    }

    // Now check if greatest in row is least in column
    // Boolean array we can use to later use to set actual saddles
    bool is_saddle[candidates_size];
    memset(&is_saddle, true, sizeof(bool) * candidates_size);
    for (size_t i = 0; i < candidates_size; i++)
        for (int y = 0; y < row_count; y++)
            if (matrix[y][candidates[i].column - 1] < value[i])
                is_saddle[i] = false;

    // Count the number of actual saddles to be able to allocate the proper result
    uint16_t saddles_capacity;
    for (size_t i = 0; i < candidates_size; i++)
        if (is_saddle[i] == true)
            saddles_capacity++;

    // Allocate Results
    saddle_points_t *saddles = malloc(sizeof(saddle_points_t) + sizeof(saddle_point_t) * saddles_capacity);
    // saddles->points = malloc(sizeof(saddle_point_t) * saddles_capacity);
    saddles->count = 0;

    // Copy valid candidates to results
    for (size_t i = 0; i < candidates_size; i++)
        if (is_saddle[i] == true)
            memmove(&saddles.points[saddles->count++], &candidates[i], sizeof(saddle_point_t));

    // Free candidates
    free(candidates);

    return saddles;
}

void free_saddle_points(saddle_points_t *to_free)
{
    // free(to_free->points);
    free(to_free);
}