#include <cstdlib>
#include <random>
#include <set>

#include "robot_name.h"

namespace robot_name
{
    const int ascii_upper_alpha_count = 26;
    const int ascii_digit_count = 10;

    std::set<std::string> existing_names;

    /* Declare and seed mersenne_twister_engine */
    std::random_device rd;
    std::mt19937 gen(rd());

    static char randomize_ascii_char()
    {
        std::uniform_int_distribution<> distrib(0, ascii_upper_alpha_count - 1);
        return 'A' + distrib(gen);
    }

    static char randomize_ascii_digit()
    {
        std::uniform_int_distribution<> distrib(0, ascii_digit_count - 1);
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
