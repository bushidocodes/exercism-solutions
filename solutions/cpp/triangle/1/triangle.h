#pragma once

namespace triangle
{
    enum flavor
    {
        equilateral,
        isosceles,
        scalene
    };

    // This doesn't document the types the template accepts
    // Unclear on how function templates should work with headers
    template <typename A, typename B, typename C>
    enum flavor
    kind(A a_length, B b_length, C c_length);

} // namespace triangle
