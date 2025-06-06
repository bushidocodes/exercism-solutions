#include "gigasecond.h"

namespace gigasecond
{

    const ptime advance(const ptime original)
    {
        return original + seconds(1'000'000'000);
    }

} // namespace gigasecond
