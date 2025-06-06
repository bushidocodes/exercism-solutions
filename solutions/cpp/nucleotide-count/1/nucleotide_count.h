#pragma once

#include <string>
#include <map>

using namespace std;

namespace nucleotide_count
{
    class counter
    {
    private:
        string strand = "";
        std::map<char, int> counts{{'A', 0},
                                   {'T', 0},
                                   {'C', 0},
                                   {'G', 0}};

    public:
        counter(string strand);
        const std::map<char, int> nucleotide_counts() const;
        int count(char c) const;
    };

} // namespace nucleotide_count
