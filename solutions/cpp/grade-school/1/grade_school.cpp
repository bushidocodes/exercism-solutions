#include "grade_school.h"
#include <iostream>
#include <algorithm>

namespace grade_school
{
    std::map<int, std::vector<std::string>> school::roster() const
    {
        return data;
    }

    std::vector<std::string> school::grade(int grade) const
    {
        if (data.count(grade) == 0)
        {
            return {};
        }

        return data.at(grade);
    }

    void school::add(std::string name, int grade)
    {
        if (data.count(grade) == 0)
        {
            data[grade] = std::vector<std::string>();
        }

        data[grade].push_back(name);
        std::sort(data[grade].begin(), data[grade].end());
    }

} // namespace grade_school
