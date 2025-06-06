#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H

#include <stdint.h>

typedef struct
{
    uint16_t row;
    uint16_t column;
} saddle_point_t;

typedef struct
{
    uint16_t count;
    saddle_point_t *points;
} saddle_points_t;

saddle_points_t *saddle_points(uint16_t row_count, uint16_t row_size, uint8_t matrix[row_count][row_size]);

void free_saddle_points(saddle_points_t *to_free);

#endif
