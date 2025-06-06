#pragma once

#include "boost/date_time/posix_time/posix_time.hpp"

namespace gigasecond
{
    using namespace boost::posix_time;

    const ptime advance(const ptime original);

} // namespace gigasecond
