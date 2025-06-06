#include "all_your_base.h"

#include <cmath>
#include <stdexcept>

namespace all_your_base
{

    digit_vec_t convert(int input_base, digit_vec_t input, int output_base)
    {
        if (input_base < 2)
            throw std::invalid_argument{"Input base must be 2 or higher!"};

        if (output_base < 2)
            throw std::invalid_argument{"Output base must be 2 or higher!"};

        /* empty input vector should return empty output vector */
        digit_vec_t output;

        if (input.size() == 0)
        {
            return output;
        }

        /* Accumulate base number system in native base-10 unsigned int */
        unsigned int sum = 0;
        unsigned int pos = 0;
        for (auto i = input.rbegin();
             i != input.rend(); i++)
        {
            /* Validate digit for input base */
            if (*i >= static_cast<unsigned int>(input_base))
            {
                throw std::invalid_argument{"Encountered digit larger than possible given input base\n"};
            }
            sum += (*i * std::pow(input_base, pos));
            pos++;
        }

        /* input vector of only zeros should return empty output vector */
        if (sum == 0)
        {
            return output;
        }

        /* Determine the most siginificant position in the output base */
        int most_significant_pos = 0;
        while (sum > std::pow(output_base, most_significant_pos + 1))
        {
            most_significant_pos++;
        }

        /* Push the digits to the vector with the desired output base */
        for (
            int i = most_significant_pos; i >= 0; i--)
        {
            int pos_val = std::pow(output_base, i);
            output.push_back(sum / pos_val);
            sum %= pos_val;
        }
        return output;
    }

} // namespace all_your_base
