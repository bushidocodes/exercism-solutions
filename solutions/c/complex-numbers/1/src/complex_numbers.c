#include "complex_numbers.h"
#include <math.h>

complex_t c_add(complex_t a, complex_t b)
{
   complex_t result = (complex_t){
       .real = a.real,
       .imag = a.imag};

   result.real += b.real;
   result.imag += b.imag;
   return result;
}

complex_t c_sub(complex_t a, complex_t b)
{
   complex_t result = (complex_t){
       .real = a.real,
       .imag = a.imag};

   result.real -= b.real;
   result.imag -= b.imag;
   return result;
}

// (a + i * b) * (c + i * d) = (a * c - b * d) + (b * c + a * d) * i.
complex_t c_mul(complex_t a, complex_t b)
{
   complex_t result;
   result.real = a.real * b.real - a.imag * b.imag;
   result.imag = a.imag * b.real + a.real * b.imag;
   return result;
}

// (a + i * b) / (c + i * d) = (a * c + b * d)/(c^2 + d^2) + (b * c - a * d)/(c^2 + d^2) * i.
complex_t c_div(complex_t a, complex_t b)
{
   complex_t result;
   result.real = (a.real * b.real + a.imag * b.imag) / (b.real * b.real + b.imag * b.imag);
   result.imag = (a.imag * b.real - a.real * b.imag) / (b.real * b.real + b.imag * b.imag);
   return result;
}

// |z| = sqrt(a^2 + b^2)
double c_abs(complex_t x)
{
   return sqrt(x.real * x.real + x.imag * x.imag);
}

// The conjugate of the number a + b * i is the number a - b * i.
complex_t c_conjugate(complex_t x)
{
   complex_t results;
   results.real = x.real;
   results.imag = -1 * x.imag;
   return results;
}

double c_real(complex_t x)
{
   return x.real;
}

double c_imag(complex_t x)
{
   return x.imag;
}

// Raising e to a complex exponent can be expressed as e^(a + i * b) = e^a * e^(i * b), the last term of which is given by Euler's formula e^(i * b) = cos(b) + i * sin(b).
// e^a * (cos(b) + i * sin(b))
// e^a * cos(b) + e^a * i * sin(b)
complex_t c_exp(complex_t x)
{
   complex_t results;
   results.real = exp(x.real) * cos(x.imag);
   results.imag = exp(x.real) * sin(x.imag);
   return results;
}
