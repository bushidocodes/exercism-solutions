#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "triangle.h"

using namespace std;

namespace triangle
{

    enum flavor
    kind(double a_length, double b_length, double c_length)
    {
        if (a_length <= 0 || b_length <= 0 || c_length <= 0)
        {
            throw std::domain_error{"Degenerate Triangle has side <= 0>"};
        }

        vector<double> args{a_length, b_length, c_length};
        sort(args.begin(), args.end());

        double sum_of_smallest = args.at(0) + args.at(1);
        double longest_length = args.at(2);

        if (longest_length >= sum_of_smallest)
        {
            throw std::domain_error{"Degenerate Triangle has side longer or equal to the sum of other two"};
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

} // namespace triangle
