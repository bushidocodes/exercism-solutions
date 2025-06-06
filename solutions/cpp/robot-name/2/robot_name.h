#pragma once
#include <string>

namespace robot_name
{

    class robot
    {
    private:
        std::string name_;

    public:
        robot();
        void reset();
        std::string name() const;
    };

} // namespace robot_name
