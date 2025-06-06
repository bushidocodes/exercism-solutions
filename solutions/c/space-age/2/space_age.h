#ifndef SPACE_AGE_H
#define SPACE_AGE_H

#include <stdint.h>

typedef enum planet {
	MERCURY = 0,
	VENUS = 1,
	EARTH = 2,
	MARS = 3,
	JUPITER = 4,
	SATURN = 5,
	URANUS = 6,
	NEPTUNE = 7,
	PLANET_COUNT = 8
} planet_t;

float age(planet_t planet, int64_t seconds);

#endif
