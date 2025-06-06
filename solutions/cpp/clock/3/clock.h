#pragma once

#include <string>

namespace date_independent {

class clock {
   private:
	int _hour;
	int _minute;
	void normalize();

   public:
	clock(int hour, int minute);
	clock plus(int minutes);

	static clock at(int hour, int minute);

	operator std::string() const;
	friend bool operator==(const clock &c1, const clock &c2);
	friend bool operator!=(const clock &c1, const clock &c2);
};

}  // namespace date_independent
