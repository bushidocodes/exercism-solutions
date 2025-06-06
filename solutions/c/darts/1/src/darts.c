#include "darts.h"
#include "math.h"

uint8_t score(coordinate_t landing_position)
{
    float distance = sqrt(pow(landing_position[0], 2) + pow(landing_position[1], 2));

    if (distance > 10)
    {
        return 0;
    }
    else if (distance > 5)
    {
        return 1;
    }
    else if (distance > 1)
    {
        return 5;
    }
    else if (distance >= 0)
    {
        return 10;
    }
    else
    {
        return 0;
    }
}