#include "word_count.h"

#include <boost/algorithm/string.hpp>
#include <vector>

namespace word_count
{

    word_count_t words(const std::string &phrase)
    {
        /* 
         * Split the string into tokens using Boost
         * By listing punctuation except for - and ' as delimeters and using token 
         * compression, this behaves similarly to strtok.
         */
        std::vector<std::string> tokens;
        boost::split(tokens, phrase, boost::is_any_of(" ,\n!!&@$%^&:.\""), boost::token_compress_on);

        word_count_t results;

        for (auto token : tokens)
        {
            /* Ignore trailing empty string produced by Boost */
            if (token.length() == 0)
                continue;

            /* Only eliminate leading or trailing single quotes to not break apostrophes */
            if (token[0] == '\'')
            {
                token.erase(0, 1);
            }
            int last_idx = token.length() - 1;
            if (token[last_idx] == '\'')
            {
                token.erase(last_idx, 1);
            }

            /* Insert/Update value of key in map */
            results[boost::algorithm::to_lower_copy(token)]++;
        }

        return results;
    }

} // namespace word_count
