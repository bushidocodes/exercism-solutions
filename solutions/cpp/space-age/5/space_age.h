#pragma once

#include <cstdint>
#include <memory>

namespace space_age {
    struct space_age {
    	explicit space_age(uint64_t age);
        ~space_age();
    	uint64_t seconds() const;
    	double on_earth() const;
    	double on_mercury() const;
    	double on_venus() const;
    	double on_mars() const;
    	double on_jupiter() const;
    	double on_saturn() const;
    	double on_uranus() const;
    	double on_neptune() const;

    private:	
        struct impl;
        impl *pImpl;
    };
}
