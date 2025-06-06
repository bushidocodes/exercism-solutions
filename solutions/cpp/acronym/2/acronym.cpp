#include "acronym.h"

#include <cctype>
#include <regex>

using namespace std;

namespace acronym {
    string acronym(const string &full) {
        /* Matches Complete Words, including apostrophes */
        regex r {"[a-zA-Z']+"};
        string acronym {""};

        auto begin {sregex_iterator(full.begin(), full.end(), r)};
        auto end {sregex_iterator()};

        for (auto i = begin; i != end; ++i) {
            smatch match {*i};
            /* Capitalize and add the first letter of each word */
            acronym.push_back(toupper(match.str().at(0)));
        }
        return acronym;
    }
} // namespace acronym

