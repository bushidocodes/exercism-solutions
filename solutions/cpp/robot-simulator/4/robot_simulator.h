#pragma once

#include <string>
#include <utility>

namespace robot_simulator {
using position_t = std::pair<int, int>;

enum class Bearing { SOUTH, NORTH, EAST, WEST };

class Robot {
private:
	position_t position;
	Bearing bearing;

public:
	Robot(position_t position = {0, 0}, Bearing = Bearing::NORTH);
	const position_t &get_position() const noexcept;
	const Bearing &get_bearing() const noexcept;
	void turn_right() noexcept;
	void turn_left() noexcept;
	void advance() noexcept;
	void execute_sequence(const std::string &sequence);
};

}  // namespace robot_simulator
