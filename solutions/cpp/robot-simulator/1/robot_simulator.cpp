#include "robot_simulator.h"

namespace robot_simulator
{
    Robot::Robot(position_t position, enum Bearing bearing) : position{position}, bearing{bearing} {};
    const position_t Robot::get_position() const
    {
        return position;
    }

    enum Bearing Robot::get_bearing() const
    {
        return bearing;
    };

    void Robot::turn_right()
    {
        switch (bearing)
        {
        case Bearing::NORTH:
            bearing = Bearing::EAST;
            break;
        case Bearing::EAST:
            bearing = Bearing::SOUTH;
            break;
        case Bearing::SOUTH:
            bearing = Bearing::WEST;
            break;
        case Bearing::WEST:
            bearing = Bearing::NORTH;
            break;
        }
    }
    void Robot::turn_left()
    {
        switch (bearing)
        {
        case Bearing::NORTH:
            bearing = Bearing::WEST;
            break;
        case Bearing::WEST:
            bearing = Bearing::SOUTH;
            break;
        case Bearing::SOUTH:
            bearing = Bearing::EAST;
            break;
        case Bearing::EAST:
            bearing = Bearing::NORTH;
            break;
        }
    }

    void Robot::advance()
    {
        switch (bearing)
        {
        case Bearing::NORTH:
            position.second++;
            break;
        case Bearing::WEST:
            position.first--;
            break;
        case Bearing::SOUTH:
            position.second--;
            break;
        case Bearing::EAST:
            position.first++;
            break;
        }
    };

    void Robot::execute_sequence(const std::string &sequence)
    {
        for (char step : sequence)
        {
            switch (step)
            {
            case 'R':
                this->turn_right();
                break;
            case 'L':
                this->turn_left();
                break;
            case 'A':
                this->advance();
                break;
            }
        }
    }

} // namespace robot_simulator
