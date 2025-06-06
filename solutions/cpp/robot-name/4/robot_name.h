#pragma once
#include <string>

namespace robot_name
{

    class robot
    {
    private:
        std::string name_;

        /* Deleting Copy and Assignment Constructors to guarantee unique robot names */
        robot &operator=(const robot &) = delete;
        robot(const robot &) = delete;

    public:
        robot();
        void reset();
        const std::string &name() const;
    };

} // namespace robot_name
