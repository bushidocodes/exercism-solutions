#include "gigasecond.h"

namespace gigasecond
{

    const ptime advance(const ptime original)
    {
        return original + seconds(1000000000);
    }

} // namespace gigasecond
