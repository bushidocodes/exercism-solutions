#include <cstdlib>
#include <set>

#include "robot_name.h"

using namespace std;

namespace robot_name
{
    set<string> existing_names;

    static char randomize_ascii_char()
    {
        return rand() % 26 + 65;
    }

    static char randomize_ascii_digit()
    {
        return rand() % 10 + 48;
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

    string robot::name() const
    {
        return name_;
    }

} // namespace robot_name
