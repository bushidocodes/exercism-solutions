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
        return (double)seconds_ / EARTH_YEAR_SECS;
    };
    double space_age::on_mercury() const
    {
        return (double)seconds_ / MERCURY_YEAR_SECS;
    };
    double space_age::on_venus() const
    {
        return (double)seconds_ / VENUS_YEAR_SECS;
    };
    double space_age::on_mars() const
    {
        return (double)seconds_ / MARS_YEAR_SECS;
    }
    double space_age::on_jupiter() const
    {
        return (double)seconds_ / JUPITER_YEAR_SECS;
    };
    double space_age::on_saturn() const
    {
        return (double)seconds_ / SATURN_YEAR_SECS;
    };
    double space_age::on_uranus() const
    {
        return (double)seconds_ / URANUS_YEAR_SECS;
    };
    double space_age::on_neptune() const
    {
        return (double)seconds_ / NEPTUNE_YEAR_SECS;
    };

} // namespace space_age
