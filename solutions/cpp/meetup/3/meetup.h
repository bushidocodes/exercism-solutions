#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup {
using months_of_year = boost::date_time::months_of_year;
using year_t = uint16_t;
using date_t = boost::gregorian::date;

class scheduler {
   private:
	months_of_year month_;
	year_t year_;
	date_t range(uint16_t start, uint16_t end_inclusive,
	             boost::date_time::weekdays day) const;
	date_t nteenth(boost::date_time::weekdays day) const;
	date_t last(boost::date_time::weekdays day) const;

   public:
	explicit scheduler(months_of_year month, year_t year);
	date_t monteenth() const;
	date_t tuesteenth() const;
	date_t wednesteenth() const;
	date_t thursteenth() const;
	date_t friteenth() const;
	date_t saturteenth() const;
	date_t sunteenth() const;
	date_t first_monday() const;
	date_t first_tuesday() const;
	date_t first_wednesday() const;
	date_t first_thursday() const;
	date_t first_friday() const;
	date_t first_saturday() const;
	date_t first_sunday() const;
	date_t second_monday() const;
	date_t second_tuesday() const;
	date_t second_wednesday() const;
	date_t second_thursday() const;
	date_t second_friday() const;
	date_t second_saturday() const;
	date_t second_sunday() const;
	date_t third_monday() const;
	date_t third_tuesday() const;
	date_t third_wednesday() const;
	date_t third_thursday() const;
	date_t third_friday() const;
	date_t third_saturday() const;
	date_t third_sunday() const;
	date_t fourth_monday() const;
	date_t fourth_tuesday() const;
	date_t fourth_wednesday() const;
	date_t fourth_thursday() const;
	date_t fourth_friday() const;
	date_t fourth_saturday() const;
	date_t fourth_sunday() const;
	date_t last_monday() const;
	date_t last_tuesday() const;
	date_t last_wednesday() const;
	date_t last_thursday() const;
	date_t last_friday() const;
	date_t last_saturday() const;
	date_t last_sunday() const;
};

}  // namespace meetup
