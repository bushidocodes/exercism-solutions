#include "queen_attack.h"

#include <cstdlib>
#include <stdexcept>

namespace queen_attack {
chess_board::chess_board(std::pair<int, int> white, std::pair<int, int> black)
    : _white{white}, _black{black} {
	if (_white.first == _black.first && _white.second == _black.second) {
		throw std::domain_error{"queen positions must be distinct\n"};
	}
}

pos_t chess_board::white() const { return _white; }
pos_t chess_board::black() const { return _black; }

bool chess_board::can_attack() const {
	return (_black.first == _white.first || _black.second == _white.second ||
	        abs(_black.first - _white.first) ==
	            abs(_black.second - _white.second));
}

chess_board::operator std::string() const {
	std::string result{
	    "_ _ _ _ _ _ _ _\n"
	    "_ _ _ _ _ _ _ _\n"
	    "_ _ _ _ _ _ _ _\n"
	    "_ _ _ _ _ _ _ _\n"
	    "_ _ _ _ _ _ _ _\n"
	    "_ _ _ _ _ _ _ _\n"
	    "_ _ _ _ _ _ _ _\n"
	    "_ _ _ _ _ _ _ _\n"};

	result[16 * _white.first + 2 * _white.second] = 'W';
	result[16 * _black.first + 2 * _black.second] = 'B';

	return result;
}

}  // namespace queen_attack
