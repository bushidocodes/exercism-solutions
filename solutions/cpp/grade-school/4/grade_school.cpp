#include "grade_school.h"
#include <algorithm>

namespace grade_school
{
    const school_roster_t &school::roster() const
    {
        return roster_;
    }

    grade_roster_t school::grade(const int grade) const
    {
        if (roster_.count(grade) == 0)
            return {};

        return roster_.at(grade);
    }

    void school::add(const std::string &name, const int grade)
    {
        auto &grade_roster = roster_[grade];

        // Returns first name in grade_roster LTE name
        auto idx = std::lower_bound(grade_roster.begin(), grade_roster.end(), name);
        grade_roster.insert(idx, name);
    }

} // namespace grade_school
