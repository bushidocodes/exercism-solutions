#pragma once

#include <string>
#include <vector>

namespace crypto_square {

class cipher {
   private:
	std::string _plaintext;

   public:
	cipher(const std::string &plaintext);
	std::string normalize_plain_text();
	std::vector<std::string> plain_text_segments();
	std::string cipher_text(bool normalize = false);
	std::string normalized_cipher_text();
};

}  // namespace crypto_square
