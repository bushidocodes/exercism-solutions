#include "robot_simulator.h"
#include <stdexcept> 

namespace robot_simulator {
Robot::Robot(position_t position, Bearing bearing)
    : position{position}, bearing{bearing} {}

const position_t &Robot::get_position() const noexcept { return position; }

const Bearing &Robot::get_bearing() const noexcept { return bearing; }

void Robot::turn_right() noexcept {
	switch (bearing) {
		case Bearing::NORTH: {
			bearing = Bearing::EAST;
			break;
        }
		case Bearing::EAST: {
			bearing = Bearing::SOUTH;
			break;
        }
		case Bearing::SOUTH: {
			bearing = Bearing::WEST;
			break;
        }
		case Bearing::WEST: {
			bearing = Bearing::NORTH;
			break;
        }
	}
}

void Robot::turn_left() noexcept {
	switch (bearing) {
		case Bearing::NORTH: {
			bearing = Bearing::WEST;
			break;
        }
		case Bearing::WEST: {
			bearing = Bearing::SOUTH;
			break;
        }
		case Bearing::SOUTH: {
			bearing = Bearing::EAST;
			break;
        }
		case Bearing::EAST: {
			bearing = Bearing::NORTH;
			break;
        }
	}
}

void Robot::advance() noexcept {
	switch (bearing) {
		case Bearing::NORTH: {
			position.second++;
			break;
        }
		case Bearing::WEST: {
			position.first--;
			break;
        }
		case Bearing::SOUTH: {
			position.second--;
			break;
        }
		case Bearing::EAST: {
			position.first++;
			break;
        }
	}
}

void Robot::execute_sequence(const std::string &sequence) {
	for (char step: sequence) {
		switch (step) {
			case 'R': {
				turn_right();
				break;
            }
			case 'L': {
				turn_left();
				break;
            }
			case 'A': {
				advance();
				break;
            }
            default: {
                throw new std::invalid_argument{"Invalid character"};
            }
		}
	}
}

}  // namespace robot_simulator
