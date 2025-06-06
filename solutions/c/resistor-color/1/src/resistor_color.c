#include "resistor_color.h"
#include "stdlib.h"
#include "stdio.h"

int color_code(resistor_band_t color)
{
    switch (color)
    {
    case BLACK:
        return 0;
    case BROWN:
        return 1;
    case RED:
        return 2;
    case ORANGE:
        return 3;
    case YELLOW:
        return 4;
    case GREEN:
        return 5;
    case BLUE:
        return 6;
    case VIOLET:
        return 7;
    case GREY:
        return 8;
    case WHITE:
        return 9;
    default:
        printf("Err!\n");
        return 0;
    }
}

resistor_band_t *colors()
{
    resistor_band_t *result = malloc(sizeof(resistor_band_t) * 10);
    result[0] = BLACK;
    result[1] = BROWN;
    result[2] = RED;
    result[3] = ORANGE;
    result[4] = YELLOW;
    result[5] = GREEN;
    result[6] = BLUE;
    result[7] = VIOLET;
    result[8] = GREY;
    result[9] = WHITE;
    return result;
}