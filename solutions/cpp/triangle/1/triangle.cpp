#include "triangle.h"
#include <stdexcept>
#include <iostream>

using namespace std;

namespace triangle
{

    template <typename A, typename B, typename C>
    enum flavor
    kind(A a_length, B b_length, C c_length)
    {
        if (a_length <= 0 || b_length <= 0 || c_length <= 0)
        {
            throw std::domain_error{"Degenerate Triangle has side <= 0>"};
        }

        double sum_of_smallest = 0.0;
        double longest_length = static_cast<double>(a_length);
        if (b_length > longest_length)
        {
            sum_of_smallest += longest_length;
            longest_length = b_length;
        }
        else
        {
            sum_of_smallest += b_length;
        }

        if (c_length > longest_length)
        {
            sum_of_smallest += longest_length;
            longest_length = c_length;
        }
        else
        {
            sum_of_smallest += c_length;
        }

        if (longest_length > sum_of_smallest)
        {
            throw std::domain_error{"Degenerate Triangle has side longer than sum of other two"};
        }

        if (a_length == b_length && b_length == c_length)
        {
            return flavor::equilateral;
        }
        else if (a_length == b_length || a_length == c_length || b_length == c_length)
        {
            return flavor::isosceles;
        }
        else
        {
            return flavor::scalene;
        }
    };

    // This feels "brute force," but unclear if or how this types should be inferred
    template enum flavor kind<>(double, double, double);
    template enum flavor kind<>(double, double, int);
    template enum flavor kind<>(double, int, double);
    template enum flavor kind<>(double, int, int);
    template enum flavor kind<>(int, double, double);
    template enum flavor kind<>(int, double, int);
    template enum flavor kind<>(int, int, double);
    template enum flavor kind<>(int, int, int);

} // namespace triangle
