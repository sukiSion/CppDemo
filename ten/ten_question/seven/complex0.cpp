#include "complex0.h"

complex::complex(double r, double v)
{
    real = r;
    virt = v;
}

complex::~complex()
{
}

complex complex::operator+(const complex &c) const
{
    return complex(real + c.real , virt + c.virt);
}
complex complex::operator-(const complex &c) const
{
    return complex(real - c.real , virt - c.virt);
}
complex complex::operator*(const complex &c) const
{
    return complex(real * c.real - virt * c.virt , real * c.virt + virt * c.real);
}
complex complex::operator*(double n) const
{
    return complex(n * real , n * virt);
}
complex complex::operator~() const
{
    return complex(real  , - virt);
}

std::ostream & operator<<(std::ostream & os, const complex & c){
    os << "(" << c.real << "," << c.virt << "i)";
    return os;
}

std::istream & operator>>(std::istream & is, complex & c){
    std::cout << "real: ";
    is >> c.real;
    std::cout << "imaginary: ";
    is >>c.virt;
    return is;
}
