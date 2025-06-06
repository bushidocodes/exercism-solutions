#include "acronym.h"

#include <cctype>
#include <regex>

namespace acronym
{
    std::string acronym(const std::string &full)
    {
        std::string acronym = "";

        /* Matches Complete Words */
        std::regex r{"[a-zA-Z]+"};

        for (
            std::sregex_iterator i = std::sregex_iterator(full.begin(), full.end(), r);
            i != std::sregex_iterator();
            ++i)
        {
            std::smatch match = *i;

            /* Capitalize and add the first letter of each word */
            acronym.push_back(std::toupper(match.str().at(0)));
        }
        return acronym;
    }

} // namespace acronym
