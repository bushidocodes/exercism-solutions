#include "anagram.h"

#include <algorithm>
#include <cctype>

namespace anagram {

anagram::anagram(std::string word) {
	std::transform(word.begin(), word.end(), word.begin(),
	               [](char c) { return std::tolower(c); });

	/* Keep track of the word itself b/c word is not anagram of itself */
	this->word_ = word;

	/* Precompute sorted letters to find anagrams */
	sorted_letters = word;
	sort(sorted_letters.begin(), sorted_letters.end());
}

std::vector<std::string> anagram::matches(
    const std::vector<std::string> &candidates) {
	std::vector<std::string> matches{};

	for (std::string candidate : candidates) {
		/* Copy string to buffer ignoring case */
		std::string candidate_buffer = candidate;
		std::transform(candidate_buffer.begin(), candidate_buffer.end(),
		               candidate_buffer.begin(),
		               [](char c) { return std::tolower(c); });

		/* Confirm the word is not identical */
		if (candidate_buffer == word_) continue;

		/* If an anagram (have same sorted letters), add to matches */
		sort(candidate_buffer.begin(), candidate_buffer.end());
		if (candidate_buffer == sorted_letters) {
			matches.push_back(candidate);
		}
	}

	return matches;
}

}  // namespace anagram
