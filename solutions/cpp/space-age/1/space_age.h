#pragma once

#include <cstdint>

namespace space_age
{

    class space_age
    {
    private:
        uint64_t seconds_;

    public:
        space_age(uint64_t age);
        uint64_t seconds() const;
        double on_earth() const;
        double on_mercury() const;
        double on_venus() const;
        double on_mars() const;
        double on_jupiter() const;
        double on_saturn() const;
        double on_uranus() const;
        double on_neptune() const;

        const static uint64_t EARTH_YEAR_SECS = 31557600;
        constexpr static uint64_t MERCURY_YEAR_SECS = EARTH_YEAR_SECS * 0.2408467;
        constexpr static uint64_t VENUS_YEAR_SECS = EARTH_YEAR_SECS * 0.61519726;
        constexpr static uint64_t MARS_YEAR_SECS = EARTH_YEAR_SECS * 1.8808158;
        constexpr static uint64_t JUPITER_YEAR_SECS = EARTH_YEAR_SECS * 11.862615;
        constexpr static uint64_t SATURN_YEAR_SECS = EARTH_YEAR_SECS * 29.447498;
        constexpr static uint64_t URANUS_YEAR_SECS = EARTH_YEAR_SECS * 84.016846;
        constexpr static uint64_t NEPTUNE_YEAR_SECS = EARTH_YEAR_SECS * 164.79132;
    };

} // namespace space_age
