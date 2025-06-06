#pragma once

#include <map>
#include <vector>

using grade_roster_t = std::vector<std::string>;
using school_roster_t = std::map<int, grade_roster_t>;

namespace grade_school
{
    class school
    {
    private:
        school_roster_t roster_;

    public:
        const school_roster_t &roster() const;
        grade_roster_t grade(int grade) const;

        void add(const std::string &name, int grade);
    };

} // namespace grade_school
