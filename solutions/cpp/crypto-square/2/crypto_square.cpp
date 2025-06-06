#include "crypto_square.h"

#include <cctype>
#include <iostream>

namespace crypto_square
{

    cipher::cipher(const std::string &plaintext)
    {
        this->_plaintext = plaintext;
    }

    std::string cipher::normalize_plain_text()
    {
        std::string buffer = "";

        for (char c : this->_plaintext)
        {
            if (std::isalnum(c))
            {
                buffer.push_back(std::tolower(c));
            }
        }
        return buffer;
    };

    std::vector<std::string> cipher::plain_text_segments()
    {
        std::string buffer = normalize_plain_text();

        int buffer_length = buffer.length();
        int c = 0;
        while (c * c < buffer_length)
            c++;

        int r = c - 1;
        if (c * r < buffer_length)
            r++;

        std::vector<std::string> text_segments;

        for (int row = 0; row < buffer_length; row += c)
        {
            std::string row_buffer = "";
            for (int column = 0; column < c && row + column < buffer_length; column++)
            {
                row_buffer.push_back(buffer.at(row + column));
            }
            text_segments.push_back(row_buffer);
        }

        return text_segments;
    }

    std::string cipher::cipher_text(bool normalize)
    {
        auto text_segments = plain_text_segments();

        size_t string_length = 0;
        if (text_segments.size() > 0)
            string_length = text_segments[0].length();

        std::string ciphertext = "";

        for (size_t i = 0; i < string_length; i++)
        {
            /* Delimit segments if normalize true */
            if (normalize && i > 0)
                ciphertext.push_back(' ');

            for (auto str : text_segments)
            {
                if (i <= str.length())
                    ciphertext.push_back(str[i]);
            }
        }
        return ciphertext;
    };

    std::string cipher::normalized_cipher_text()
    {
        return cipher_text(true);
    };

} // namespace crypto_square
