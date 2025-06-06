#pragma once

#include <string>

namespace phone_number
{
    class phone_number
    {
    private:
        std::string normalized;

    public:
        phone_number(const std::string &raw);
        std::string number();
        std::string area_code();
        operator std::string() const;
    };

} // namespace phone_number
