#pragma once

namespace triangle {
    enum class flavor { equilateral, isosceles, scalene };
    
    flavor kind(double a_length, double b_length, double c_length);

}
