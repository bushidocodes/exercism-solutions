#include "grade_school.h"
#include <iostream>
#include <algorithm>

namespace grade_school
{
    const school_roster_t &school::roster() const
    {
        return roster_;
    }

    grade_roster_t school::grade(int grade) const
    {
        if (roster_.count(grade) == 0)
        {
            return {};
        }

        return roster_.at(grade);
    }

    void school::add(const std::string &name, int grade)
    {
        grade_roster_t &grade_roster = roster_[grade];
        auto idx = std::lower_bound(grade_roster.begin(), grade_roster.end(), name);
        grade_roster.insert(idx, name);
    }

} // namespace grade_school
