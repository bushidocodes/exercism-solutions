#pragma once

#include <string>
#include <utility>

namespace robot_simulator
{
    using position_t = std::pair<int, int>;

    enum Bearing
    {
        SOUTH,
        NORTH,
        EAST,
        WEST
    };

    class Robot
    {
    private:
        position_t position;
        enum Bearing bearing;

    public:
        Robot(position_t position = {0, 0}, enum Bearing = Bearing::NORTH);
        const position_t get_position() const;
        enum Bearing get_bearing() const;
        void turn_right();
        void turn_left();
        void advance();
        void execute_sequence(const std::string &sequence);
    };

} // namespace robot_simulator
