#include "space_age.h"

namespace space_age
{

    space_age::space_age(uint64_t seconds) : seconds_{seconds} {};

    uint64_t space_age::seconds() const
    {
        return seconds_;
    };
    double space_age::on_earth() const
    {
        return static_cast<double>(seconds_) / EARTH_YEAR_SECS;
    };
    double space_age::on_mercury() const
    {
        return static_cast<double>(seconds_) / MERCURY_YEAR_SECS;
    };
    double space_age::on_venus() const
    {
        return static_cast<double>(seconds_) / VENUS_YEAR_SECS;
    };
    double space_age::on_mars() const
    {
        return static_cast<double>(seconds_) / MARS_YEAR_SECS;
    }
    double space_age::on_jupiter() const
    {
        return static_cast<double>(seconds_) / JUPITER_YEAR_SECS;
    };
    double space_age::on_saturn() const
    {
        return static_cast<double>(seconds_) / SATURN_YEAR_SECS;
    };
    double space_age::on_uranus() const
    {
        return static_cast<double>(seconds_) / URANUS_YEAR_SECS;
    };
    double space_age::on_neptune() const
    {
        return static_cast<double>(seconds_) / NEPTUNE_YEAR_SECS;
    };

} // namespace space_age
