#include "secret_handshake.h"

#include <algorithm>
#include <bitset>
#include <utility>

using namespace std;

namespace secret_handshake {
    using handshake_event_t = pair<uint8_t, string>;

    constexpr uint8_t wink_mask = 0b00001;
    constexpr uint8_t double_blink_mask = 0b00010;
    constexpr uint8_t close_your_eyes_mask = 0b00100;
    constexpr uint8_t jump_mask = 0b01000;
    constexpr uint8_t reverse_mask = 0b10000;
    
    const vector<handshake_event_t> handshake_events = {
        {wink_mask, "wink"},
        {double_blink_mask, "double blink"},
        {close_your_eyes_mask, "close your eyes"},
        {jump_mask, "jump"}};

    vector<string> commands(uint8_t handshake_int) {
        vector<std::string> handshake;

        for (auto handshake_event : handshake_events) {
            if (handshake_int & handshake_event.first) {
                handshake.push_back(handshake_event.second);
            }
        }

        if (handshake_int & reverse_mask) {
            std::reverse(handshake.begin(), handshake.end());
        }
        
        return handshake;
    }

} // namespace secret_handshake
