#pragma once

#include <string>

namespace atbash_cipher
{
    std::string encode(const std::string &plaintext);
    std::string decode(const std::string &ciphertext);
} // namespace atbash_cipher
