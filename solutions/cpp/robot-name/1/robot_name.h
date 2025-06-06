#pragma once
#include <string>

using namespace std;

namespace robot_name
{

    class robot
    {
    private:
        string name_;

    public:
        robot();
        void reset();
        string name() const;
    };

} // namespace robot_name
