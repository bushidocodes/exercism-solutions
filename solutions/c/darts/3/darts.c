#include "darts.h"

#include "math.h"

uint8_t score(coordinate_t landing_position) {
	float distance =
	    sqrt(pow(landing_position[0], 2) + pow(landing_position[1], 2));
	uint8_t score;

	if (distance > 10)
		score = 0;
	else if (distance > 5)
		score = 1;
	else if (distance > 1)
		score = 5;
	else if (distance >= 0)
		score = 10;
	else
		score = 0;

	return score;
}