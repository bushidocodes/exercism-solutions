#include "meetup.h"

#include <stdexcept>

namespace meetup {

scheduler::scheduler(months_of_year month, year_t year)
    : month_{month}, year_{year} {}

date_t scheduler::range(uint16_t start, uint16_t end_inclusive,
                        boost::date_time::weekdays day) const {
	if (end_inclusive - start != 6) {
		throw new std::invalid_argument{
		    "Start and End date (inclusive) must form a consecutive range of 7 "
		    "days"};
	}

	/* This feels like unnecessary copies, but I'm unsure how to change a boost
	 * date's day after declaration */
	date_t result;
	for (uint16_t nth_day = start; nth_day <= end_inclusive; nth_day++) {
		date_t candidate{year_, month_, nth_day};
		if (candidate.day_of_week() == day) result = candidate;
	}
	return result;
}

date_t scheduler::nteenth(boost::date_time::weekdays day) const {
	return range(13, 19, day);
}

date_t scheduler::last(boost::date_time::weekdays day) const {
	/* This feels wasteful to instantiate a class to get the length of the
	 * month, but Boost dates are immutable */
	date_t month{year_, month_, 1};
	int end_of_month = month.end_of_month().day();
	return range(end_of_month - 6, end_of_month, day);
}

date_t scheduler::monteenth() const {
	return nteenth(boost::date_time::Monday);
}

date_t scheduler::tuesteenth() const {
	return nteenth(boost::date_time::Tuesday);
}

date_t scheduler::wednesteenth() const {
	return nteenth(boost::date_time::Wednesday);
}

date_t scheduler::thursteenth() const {
	return nteenth(boost::date_time::Thursday);
}

date_t scheduler::friteenth() const {
	return nteenth(boost::date_time::Friday);
}

date_t scheduler::saturteenth() const {
	return nteenth(boost::date_time::Saturday);
}

date_t scheduler::sunteenth() const {
	return nteenth(boost::date_time::Sunday);
}

date_t scheduler::first_monday() const {
	return range(1, 7, boost::date_time::Monday);
}

date_t scheduler::first_tuesday() const {
	return range(1, 7, boost::date_time::Tuesday);
}

date_t scheduler::first_wednesday() const {
	return range(1, 7, boost::date_time::Wednesday);
}

date_t scheduler::first_thursday() const {
	return range(1, 7, boost::date_time::Thursday);
}

date_t scheduler::first_friday() const {
	return range(1, 7, boost::date_time::Friday);
}

date_t scheduler::first_saturday() const {
	return range(1, 7, boost::date_time::Saturday);
}

date_t scheduler::first_sunday() const {
	return range(1, 7, boost::date_time::Sunday);
}

date_t scheduler::second_monday() const {
	return range(8, 14, boost::date_time::Monday);
}

date_t scheduler::second_tuesday() const {
	return range(8, 14, boost::date_time::Tuesday);
}

date_t scheduler::second_wednesday() const {
	return range(8, 14, boost::date_time::Wednesday);
}

date_t scheduler::second_thursday() const {
	return range(8, 14, boost::date_time::Thursday);
}

date_t scheduler::second_friday() const {
	return range(8, 14, boost::date_time::Friday);
}

date_t scheduler::second_saturday() const {
	return range(8, 14, boost::date_time::Saturday);
}

date_t scheduler::second_sunday() const {
	return range(8, 14, boost::date_time::Sunday);
}

date_t scheduler::third_monday() const {
	return range(15, 21, boost::date_time::Monday);
}

date_t scheduler::third_tuesday() const {
	return range(15, 21, boost::date_time::Tuesday);
}

date_t scheduler::third_wednesday() const {
	return range(15, 21, boost::date_time::Wednesday);
}

date_t scheduler::third_thursday() const {
	return range(15, 21, boost::date_time::Thursday);
}

date_t scheduler::third_friday() const {
	return range(15, 21, boost::date_time::Friday);
}

date_t scheduler::third_saturday() const {
	return range(15, 21, boost::date_time::Saturday);
}

date_t scheduler::third_sunday() const {
	return range(15, 21, boost::date_time::Sunday);
}

date_t scheduler::fourth_monday() const {
	return range(22, 28, boost::date_time::Monday);
}

date_t scheduler::fourth_tuesday() const {
	return range(22, 28, boost::date_time::Tuesday);
}

date_t scheduler::fourth_wednesday() const {
	return range(22, 28, boost::date_time::Wednesday);
}

date_t scheduler::fourth_thursday() const {
	return range(22, 28, boost::date_time::Thursday);
}

date_t scheduler::fourth_friday() const {
	return range(22, 28, boost::date_time::Friday);
}

date_t scheduler::fourth_saturday() const {
	return range(22, 28, boost::date_time::Saturday);
}

date_t scheduler::fourth_sunday() const {
	return range(22, 28, boost::date_time::Sunday);
}

date_t scheduler::last_monday() const { return last(boost::date_time::Monday); }

date_t scheduler::last_tuesday() const {
	return last(boost::date_time::Tuesday);
}

date_t scheduler::last_wednesday() const {
	return last(boost::date_time::Wednesday);
}

date_t scheduler::last_thursday() const {
	return last(boost::date_time::Thursday);
}

date_t scheduler::last_friday() const { return last(boost::date_time::Friday); }

date_t scheduler::last_saturday() const {
	return last(boost::date_time::Saturday);
}

date_t scheduler::last_sunday() const { return last(boost::date_time::Sunday); }

}  // namespace meetup
