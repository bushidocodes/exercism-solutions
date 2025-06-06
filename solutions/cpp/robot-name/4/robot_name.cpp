#include <cstdlib>
#include <random>
#include <set>

#include "robot_name.h"

namespace robot_name
{

    std::set<std::string> existing_names;

    /* Declare and seed mersenne_twister_engine */
    std::random_device rd;
    std::mt19937 gen(rd());

    static char randomize_ascii_char()
    {
        std::uniform_int_distribution<> distrib(0, 'Z' - 'A');
        return 'A' + distrib(gen);
    }

    static char randomize_ascii_digit()
    {
        std::uniform_int_distribution<> distrib(0, '9' - '0');
        return '0' + distrib(gen);
    }

    robot::robot()
    {
        reset();
    }

    void robot::reset()
    {
        do
        {
            name_.clear();
            name_.push_back(randomize_ascii_char());
            name_.push_back(randomize_ascii_char());
            name_.push_back(randomize_ascii_digit());
            name_.push_back(randomize_ascii_digit());
            name_.push_back(randomize_ascii_digit());
        } while (existing_names.find(name_) != existing_names.end());

        existing_names.insert(name_);
    }

    const std::string &robot::name() const
    {
        return name_;
    }

} // namespace robot_name
