#include "bob.h"

#include <cctype>
#include <map>

namespace bob
{
    enum class response_type
    {
        question,
        forceful_question,
        statement,
        forceful_statement,
        silence
    };

    using response_t = enum class response_type;

    std::map<response_t, std::string> responses{
        {response_type::question, "Sure."},
        {response_type::forceful_question, "Calm down, I know what I'm doing!"},
        {response_type::statement, "Whatever."},
        {response_type::forceful_statement, "Whoa, chill out!"},
        {response_type::silence, "Fine. Be that way!"}
    };

    response_t classify(const std::string &statement)
    {
        bool has_char = false;
        bool has_alpha = false;
        bool is_forceful = true;
        bool is_question = false;

        for (auto it = statement.rbegin(); it < statement.rend(); it++)
        {
            if (!std::isspace(*it))
            {
                /* A question is defined as the trailing non whitespace being '?' */
                if (!has_char && *it == '?')
                {
                    is_question = true;
                }

                has_char = true;

                if (std::islower(*it))
                {
                    has_alpha = true;
                    is_forceful = false;
                }
                else if (std::isalpha(*it))
                {
                    has_alpha = true;
                }
            }
        }

        /* 
         * Because assume forceful and disprove by checking for lowercase, 
         * if we've found no alphabetic characters at all, set to false  
         */
        if (!has_alpha)
        {
            is_forceful = false;
        }

        if (!has_char)
            return response_type::silence;

        if (is_forceful && is_question)
            return response_type::forceful_question;

        if (is_question)
            return response_type::question;

        if (is_forceful)
            return response_type::forceful_statement;

        return response_type::statement;
    }

    std::string hey(const std::string &statement)
    {
        return responses.at(classify(statement));
    }

} // namespace bob
