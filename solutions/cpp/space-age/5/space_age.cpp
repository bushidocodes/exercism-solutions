#include "space_age.h"

namespace space_age {
    constexpr static double EARTH_YEAR_SECS = 31557600;
    constexpr static double MERCURY_YEAR_SECS = EARTH_YEAR_SECS * 0.2408467;
    constexpr static double VENUS_YEAR_SECS = EARTH_YEAR_SECS * 0.61519726;
    constexpr static double MARS_YEAR_SECS = EARTH_YEAR_SECS * 1.8808158;
    constexpr static double JUPITER_YEAR_SECS = EARTH_YEAR_SECS * 11.862615;
    constexpr static double SATURN_YEAR_SECS = EARTH_YEAR_SECS * 29.447498;
    constexpr static double URANUS_YEAR_SECS = EARTH_YEAR_SECS * 84.016846;
    constexpr static double NEPTUNE_YEAR_SECS = EARTH_YEAR_SECS * 164.79132;

    struct space_age::impl {
        uint64_t secs;
        impl(uint64_t _secs) :secs{_secs} {}
    };

    space_age::space_age(uint64_t _secs) : pImpl{new impl(_secs)} {}

    space_age::~space_age() {
        delete pImpl;
    }
    
    uint64_t space_age::seconds() const { return pImpl->secs; }
    
    double space_age::on_earth() const {
    	return static_cast<double>(pImpl->secs) / EARTH_YEAR_SECS;
    }
    
    double space_age::on_mercury() const {
    	return static_cast<double>(pImpl->secs) / MERCURY_YEAR_SECS;
    }
    
    double space_age::on_venus() const {
    	return static_cast<double>(pImpl->secs) / VENUS_YEAR_SECS;
    }
    
    double space_age::on_mars() const {
    	return static_cast<double>(pImpl->secs) / MARS_YEAR_SECS;
    }
    
    double space_age::on_jupiter() const {
    	return static_cast<double>(pImpl->secs) / JUPITER_YEAR_SECS;
    }
    
    double space_age::on_saturn() const {
    	return static_cast<double>(pImpl->secs) / SATURN_YEAR_SECS;
    }
    
    double space_age::on_uranus() const {
    	return static_cast<double>(pImpl->secs) / URANUS_YEAR_SECS;
    }
    
    double space_age::on_neptune() const {
    	return static_cast<double>(pImpl->secs) / NEPTUNE_YEAR_SECS;
    }

}
