#include "word_count.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Tokenize on whitespace and punctuation, other than single quotes,
// which can potentially be apostrophes that need to be preserved
static const char terminators[] = " ,\n:!&@$%^&.";
static const size_t terminators_length = 13;

static inline bool is_terminator(char c) {
    for (size_t i = 0; i < terminators_length; ++i) {
        if (c == terminators[i]) return true;
    }
    return false;
}

///
/// @brief Trims leading and trailing single quotes from a span
///
/// @param[in] text - input text
/// @param[in,out] offset - base offset of span
/// @param[in,out] length - length of span starting at offset
///
static inline void strip_non_apostrophes(const char text[const static 1], size_t* offset, size_t* length) {
	while (*length > 0 && text[*offset] == '\'') {
        (*offset)++;
        (*length)--;
    }

	while (*length > 0 && text[*offset + *length - 1] == '\'') {
        (*length)--;
    }
}

///
/// @brief Zero initializes bank of words
///
/// @param[in,out] words - bank of words
///
static inline void words_init(word_count_word_t words[const static MAX_WORDS]) {
	for (int i = 0; i < MAX_WORDS; ++i) {
        memset(&words[i].text, 0, MAX_WORD_LENGTH + 1);
		words[i].count = 0;
	}
}

///
/// @brief Log words to stdout
///
/// @param[in] words - bank of words
///
static inline void words_log(const word_count_word_t words[const static MAX_WORDS], int word_count) {
	for (int i = 0; i < word_count; ++i) {
        printf("{%s, %d}\n", words[i].text, words[i].count);
	}
}

///
/// @brief case-insensitive comparison of two strings of length len
///
/// @param[in] a - non-null cstr
/// @param[in] b - non-null cstr
///
/// @returns true if equal, false otherwise
///
static inline bool ci_string_equal(const char a[const static 1], const char b[const static 1], size_t len){
    for (size_t i = 0; i < len; ++i){
        if (toupper(a[i]) != toupper(b[i])) {
            return false;
        }
    }
    return true;
}

///
/// @brief Count the number of unique words in a string
///
/// @param[in] input_text
/// @param[out] words
///
/// @returns number of words in words bank on success
///          EXCESSIVE_LENGTH_WORD if a word in input_text was longer than MAX_WORD_LENGTH
///          EXCESSIVE_NUMBER_OF_WORDS if the unique count of words in input_text exceeded MAX_WORDS
///
int count_words(const char input_text[static 1], word_count_word_t words[static MAX_WORDS]) {
	words_init(words);
	int words_count = 0;

	// Copy input text by value and make case insensitive
    size_t input_text_len = strlen(input_text);

	for (size_t cur = 0; cur < input_text_len; /**/) {

        //
        // Advance Cursor past leading terminators
        //
        while (cur < input_text_len && is_terminator(input_text[cur])) cur++;

        //
        // stride_length is count number of non-terminators
        // This is what we advance the cursor by at end of loop iteration
        // 
        size_t stride_length = 0;
        while ((cur + stride_length) < input_text_len && !is_terminator(input_text[cur + stride_length]))
            stride_length++;

        //
        // A span_length is shorter than a stride_length after trimming leading and trailing \'
        //
        size_t span_length = stride_length;
        strip_non_apostrophes(input_text, &cur, &span_length);

        if (span_length > MAX_WORD_LENGTH) {
            return EXCESSIVE_LENGTH_WORD;
        }
    
        if (span_length > 0) {
            bool didAdd = false;
    		for (int i = 0; i < words_count; ++i) {
    			size_t word_length = strlen(words[i].text);
                if (span_length == word_length && ci_string_equal(words[i].text, &input_text[cur], word_length)) {
    				words[i].count++;
                    didAdd = true;
    				break;
    			}
            }
    
            if (!didAdd) {
    			if (words_count == MAX_WORDS) {
                    return EXCESSIVE_NUMBER_OF_WORDS;
                }

                for (size_t j = 0; j < span_length; ++j) {
                    words[words_count].text[j] = tolower(input_text[cur + j]);
                }
                words[words_count].text[span_length] = '\0';
                words[words_count].count = 1;
                words_count++;
            }
        }
        
        //
        // Advance Cursor past stride
        //
        cur += stride_length;
	}

	return words_count;
}