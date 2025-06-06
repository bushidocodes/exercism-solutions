#include "binary.h"
#include <bitset>
#include <stdexcept>

namespace binary
{
    unsigned long convert(const std::string &binary)
    {
        std::bitset<64> buffer;
        std::size_t binary_length = binary.length() - 1;
        for (std::size_t i = 0; i <= binary_length; i++)
        {
            if (binary[binary_length - i] == '1')
            {
                buffer[i] = true;
            }
            else if (binary[binary_length - i] != '0')
            {
                /* Character was neither 0 nor 1, so return 0 to signify invalid */
                return 0;
            }
        }
        return buffer.to_ulong();
    }

} // namespace binary
