#include "space_age.h"

namespace space_age {

    space_age::space_age(uint64_t _secs) : secs{_secs} {}
    
    uint64_t space_age::seconds() const { return secs; }
    
    double space_age::on_earth() const {
    	return static_cast<double>(secs) / EARTH_YEAR_SECS;
    }
    
    double space_age::on_mercury() const {
    	return static_cast<double>(secs) / MERCURY_YEAR_SECS;
    }
    
    double space_age::on_venus() const {
    	return static_cast<double>(secs) / VENUS_YEAR_SECS;
    }
    
    double space_age::on_mars() const {
    	return static_cast<double>(secs) / MARS_YEAR_SECS;
    }
    
    double space_age::on_jupiter() const {
    	return static_cast<double>(secs) / JUPITER_YEAR_SECS;
    }
    
    double space_age::on_saturn() const {
    	return static_cast<double>(secs) / SATURN_YEAR_SECS;
    }
    
    double space_age::on_uranus() const {
    	return static_cast<double>(secs) / URANUS_YEAR_SECS;
    }
    
    double space_age::on_neptune() const {
    	return static_cast<double>(secs) / NEPTUNE_YEAR_SECS;
    }

}
