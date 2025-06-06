#pragma once

#include <set>
#include <string>
#include <vector>

namespace anagram {

class anagram {
   private:
	std::string sorted_letters;
	std::string word_;

   public:
	anagram(std::string word);
	std::vector<std::string> matches(
	    const std::vector<std::string> &candidates);
};

}  // namespace anagram
