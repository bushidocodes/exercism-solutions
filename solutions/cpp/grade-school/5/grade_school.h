#pragma once

#include <map>
#include <vector>

namespace grade_school
{
    using grade_roster_t = std::vector<std::string>;
    using school_roster_t = std::map<int, grade_roster_t>;

    static const grade_roster_t empty_roster {};

    class school
    {
        school_roster_t roster_;

    public:
        const school_roster_t &roster() const;
        const grade_roster_t &grade(int grade) const;

        void add(const std::string &name, const int grade);
    };

} // namespace grade_school
