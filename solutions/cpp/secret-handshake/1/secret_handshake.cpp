#include "secret_handshake.h"

#include <algorithm>
#include <bitset>
#include <utility>

namespace secret_handshake
{
    using handshake_event_t = std::pair<std::uint8_t, std::string>;
    
    const std::vector<handshake_event_t> handshake_events = {
        {0, "wink"},
        {1, "double blink"},
        {2, "close your eyes"},
        {3, "jump"},
        {4, "reverse"}};

    std::vector<std::string>
    commands(std::uint8_t handshake_int)
    {
        std::bitset<5> handshake_bitset{handshake_int};
        std::vector<std::string> handshake;

        for (auto handshake_event : handshake_events)
            if (handshake_bitset[handshake_event.first])
            {
                if (handshake_event.second == "reverse")
                {
                    std::reverse(handshake.begin(), handshake.end());
                }
                else
                {
                    handshake.push_back(handshake_event.second);
                }
            }

        return handshake;
    }

} // namespace secret_handshake
