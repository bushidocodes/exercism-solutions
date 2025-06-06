#include "clock.h"

#include <cstring>

namespace date_independent {

void clock::normalize() {
	while (_minute < 0) {
		_hour -= 1;
		_minute += 60;
	}

	_hour += _minute / 60;
	_minute %= 60;

	while (_hour < 0) {
		_hour += 24;
	}

	_hour %= 24;
}

clock::clock(int hour, int minute) {
	_hour = hour;
	_minute = minute;
	normalize();
}

clock clock::plus(int minutes) {
	_minute += minutes;
	normalize();
	return *this;
}

clock clock::at(int hour, int minute) {
	clock new_clock{hour, minute};
	return new_clock;
}

clock::operator std::string() const {
	char buffer[6];
	std::sprintf(buffer, "%02d:%02d", _hour, _minute);

	std::string result{buffer};

	return result;
}

bool operator==(const clock &c1, const clock &c2) {
	return c1._hour == c2._hour && c1._minute == c2._minute;
}

bool operator!=(const clock &c1, const clock &c2) { return !(c1 == c2); }
}  // namespace date_independent
