#pragma once

#include <map>
#include <vector>

namespace grade_school
{
    class school
    {
    private:
        std::map<int, std::vector<std::string>> data;

    public:
        std::map<int, std::vector<std::string>> roster() const;
        std::vector<std::string> grade(int grade) const;

        void add(std::string name, int grade);
    };

} // namespace grade_school
