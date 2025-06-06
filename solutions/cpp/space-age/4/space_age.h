#pragma once

#include <cstdint>

namespace space_age {
    class space_age {
    	uint64_t secs;
    
    public:
    	explicit space_age(uint64_t age);
    	uint64_t seconds() const;
    	double on_earth() const;
    	double on_mercury() const;
    	double on_venus() const;
    	double on_mars() const;
    	double on_jupiter() const;
    	double on_saturn() const;
    	double on_uranus() const;
    	double on_neptune() const;
    
    	constexpr static uint64_t EARTH_YEAR_SECS = 31557600;
    	constexpr static double MERCURY_YEAR_SECS = EARTH_YEAR_SECS * 0.2408467;
    	constexpr static double VENUS_YEAR_SECS = EARTH_YEAR_SECS * 0.61519726;
    	constexpr static double MARS_YEAR_SECS = EARTH_YEAR_SECS * 1.8808158;
    	constexpr static double JUPITER_YEAR_SECS = EARTH_YEAR_SECS * 11.862615;
    	constexpr static double SATURN_YEAR_SECS = EARTH_YEAR_SECS * 29.447498;
    	constexpr static double URANUS_YEAR_SECS = EARTH_YEAR_SECS * 84.016846;
    	constexpr static double NEPTUNE_YEAR_SECS = EARTH_YEAR_SECS * 164.79132;
    };
}
