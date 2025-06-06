#include "space_age.h"

#define SECS_PER_MIN 60
#define MINS_PER_HOUR 60
#define EARTH_HOURS_PER_DAY 24
#define EARTH_DAYS_PER_YEAR 365.25
#define JUPITER_YEARS_PER_EARTH_YEAR 11.862615

const float ORBITAL_PERIOD_IN_EARTH_YEAR[PLANET_COUNT] = {
    [MERCURY] = 0.2408467,
    [VENUS] = 0.61519726,
    [EARTH] = 1.0,
    [MARS] = 1.8808158,
    [JUPITER] = 11.862615,
    [SATURN] = 29.447498,
    [URANUS] = 84.016846,
    [NEPTUNE] = 164.79132};

float convert_planet_age(planet_t planet, int64_t input)
{
    float age_in_earth_years = input / SECS_PER_MIN / MINS_PER_HOUR / EARTH_HOURS_PER_DAY / EARTH_DAYS_PER_YEAR;
    return age_in_earth_years / ORBITAL_PERIOD_IN_EARTH_YEAR[planet];
}