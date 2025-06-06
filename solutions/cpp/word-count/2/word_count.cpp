#include "word_count.h"

#include <algorithm>
#include <cctype>
#include <regex>
#include <vector>

namespace word_count
{
    std::map<std::string, int> words(const std::string &phrase)
    {
        /* Split into a vector of words */
        /* the '-1' is what makes the regex split (-1 := what was not matched) */
        std::regex re("[ ,\n]");
        std::sregex_token_iterator first{phrase.begin(), phrase.end(), re, -1};
        std::sregex_token_iterator last;
        std::vector<std::string> tokens{first, last};

        /* Cleanup tokens */
        std::for_each(tokens.begin(), tokens.end(), [](auto &tok){
            /* Remove leading or trailing quotes */
            if (tok[0] == '\'') tok.erase(0, 1);
            if (tok.size() > 0 && tok[tok.size() - 1] == '\'') tok.erase(tok.size() - 1, 1);

            /* Remote all punctuation other than apostrophes */
            tok.erase(std::remove_if(tok.begin(), tok.end(), [](unsigned char c){
                return std::ispunct(c) &&  c != '\'';
            }), tok.end());

            /* Cast to lowercase */
            std::transform(tok.begin(), tok.end(), tok.begin(), [](unsigned char c){
                return std::tolower(c);
            });
        });

        /* Remove empty tokens */
        tokens.erase(std::remove_if(tokens.begin(), tokens.end(), [](auto tok){
            return tok.empty();
        }), tokens.end());

        /* Reduce into a word count */
        std::map<std::string, int> results;
        for (auto tok: tokens){
            results[tok]++;
        }
        
        return results;
    }

} // namespace word_count
