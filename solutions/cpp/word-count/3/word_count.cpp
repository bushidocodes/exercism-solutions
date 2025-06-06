#include "word_count.h"

#include <algorithm>
#include <cctype>
#include <regex>
#include <vector>

using namespace std;

namespace word_count {
    auto words(const string &phrase) -> map<string, int> {
        /* Split into a vector of words */
        /* the '-1' is what makes the regex split (-1 := what was not matched) */
        regex re{"[ ,\n]"};
        sregex_token_iterator first{phrase.begin(), phrase.end(), re, -1};
        sregex_token_iterator last;
        vector<string> words{first, last};

        /* Cleanup words */
        for_each(words.begin(), 
                 words.end(), 
                 [](auto &word) {
                     /* Remove leading or trailing quotes */
                     if (word.front() == '\'') word.erase(word.begin());
                     if (word.size() > 0 && word.back() == '\'') word.pop_back();
        
                     /* Remote all punctuation other than apostrophes */
                     word.erase(remove_if(word.begin(),
                                          word.end(),
                                          [](auto c){ return ispunct(c) && c != '\''; }),
                                word.end());
        
                     /* Cast to lowercase */
                     transform(word.begin(),
                               word.end(),
                               word.begin(),
                               [](auto c){ return tolower(c); });
                 });

        /* Remove empty words */
        words.erase(remove_if(words.begin(),
                              words.end(),
                              [](auto word){ return word.empty(); }),
                    words.end());

        /* Reduce into a word count */
        map<string, int> results;
        for (auto word: words){
            results[word]++;
        }
        
        return results;
    }
} // namespace word_count
