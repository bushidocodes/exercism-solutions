#pragma once

#include <string>
#include <map>

namespace nucleotide_count
{
    class counter
    {
    private:
        std::map<char, int> counts{{'A', 0},
                                   {'T', 0},
                                   {'C', 0},
                                   {'G', 0}};

        bool validate_nucleotide(char nucleotide) const;

    public:
        explicit counter(const std::string &strand);
        const std::map<char, int> &nucleotide_counts() const noexcept;
        int count(char c) const;
    };

} // namespace nucleotide_count
