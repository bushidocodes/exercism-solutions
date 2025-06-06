#include "atbash_cipher.h"

#include <cctype>

namespace atbash_cipher
{
    // std::string encode(const std::string_view plaintext){
    //     return plaintext 
    //         | std::views::filter([](auto c){return std::isalnum(c);})
    //         | std::views::transform([](auto c){return std::isalpha(c) ? 'z' - (std::tolower(c) - 'a') : c;})
    //         | std::views::chunk(5)
    //         | std::views::join_with(' ')
    //         | std::ranges::to<std::string>();
    // };
    
    std::string encode(const std::string &plaintext)
    {
        std::string ciphertext = "";

        for (char c : plaintext)
        {
            if (!std::isalnum(c))
                continue;

            size_t ciphertext_length = ciphertext.length();
            if (ciphertext_length > 0 && (ciphertext_length + 1) % 6 == 0)
            {
                ciphertext.push_back(' ');
            }

            if (std::isalpha(c))
            {
                ciphertext.push_back('a' + 'z' - std::tolower(c));
            }
            else
            {
                ciphertext.push_back(c);
            }
        }
        return ciphertext;
    }

    // std::string decode(const std::string_view ciphertext){
    //     return ciphertext
    //         | std::views::filter([](char c){return std::isalnum(c);})
    //         | std::views::transform([](auto c){return std::isalpha(c) ? 'z' - (std::tolower(c) - 'a') : c;})
    //         | std::ranges::to<std::string>();
    // };

    std::string decode(const std::string &ciphertext)
    {
        std::string plaintext = "";

        for (char c : ciphertext)
        {
            if (!std::isalnum(c))
                continue;

            if (std::isalpha(c))
            {
                plaintext.push_back('a' + ('z' - std::tolower(c)));
            }
            else
            {
                plaintext.push_back(c);
            }
        }
        return plaintext;
    }

} // namespace atbash_cipher
