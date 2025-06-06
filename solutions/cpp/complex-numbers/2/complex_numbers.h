#pragma once

#include <cmath>

namespace complex_numbers
{
    class Complex
    {
    private:
        double _real;
        double _imag;

    public:
        Complex(double real, double imag)
        {
            _real = real;
            _imag = imag;
        };

        double real() const
        {
            return _real;
        }

        double imag() const
        {
            return _imag;
        }

        double abs() const
        {
            return std::sqrt(_real * _real + _imag * _imag);
        }

        Complex conj() const
        {
            return Complex{_real, -1 * _imag};
        }

        Complex exp() const
        {
            return Complex{
                std::exp(_real) * std::cos(_imag),
                std::exp(_real) * std::sin(_imag)};
        }

        friend Complex operator+(Complex const &first, Complex const &second)
        {
            return Complex{
                first._real + second._real,
                first._imag + second._imag};
        }

        friend Complex operator-(Complex const &first, Complex const &second)
        {
            return Complex{
                first._real - second._real,
                first._imag - second._imag};
        }

        friend Complex operator*(Complex const &first, Complex const &second)
        {
            return Complex{
                first._real * second._real - first._imag * second._imag, first._real * second._imag + first._imag * second._real};
        }

        friend Complex operator/(Complex const &first, Complex const &second)
        {
            return Complex{
                (first._real * second._real + first._imag * second._imag) / (second._real * second._real + second._imag * second._imag), (first._imag * second._real - first._real * second._imag) / (second._real * second._real + second._imag * second._imag)};
        }
    };

} // namespace complex_numbers
