#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace secret_handshake
{
    using handshake_t = std::vector<std::string>;
    handshake_t commands(std::uint8_t handshake_int);
} // namespace secret_handshake
