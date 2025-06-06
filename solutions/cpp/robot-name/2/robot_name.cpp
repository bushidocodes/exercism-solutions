#include <cstdlib>
#include <set>

#include "robot_name.h"

namespace robot_name
{
    const uint32_t ASCII_CHAR_COUNT = 26;
    const uint32_t ASCII_DIGIT_COUNT = 10;
    std::set<std::string> existing_names;

    static char randomize_ascii_char()
    {
        return rand() % ASCII_CHAR_COUNT + 'A';
    }

    static char randomize_ascii_digit()
    {
        return rand() % ASCII_DIGIT_COUNT + '0';
    }

    robot::robot()
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

    std::string robot::name() const
    {
        return name_;
    }

} // namespace robot_name
