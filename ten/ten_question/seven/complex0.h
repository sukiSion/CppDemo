#ifndef _COMPLEX0_H_
#define _COMPLEX0_H_

#include<iostream>
class complex{
    private:
    double real;
    double virt;
    public:
    complex(double r = 0.0 , double v = 0.0);
    ~complex();

    complex operator+(const complex & c) const;
    complex operator-(const complex & c) const;
    complex operator*(const complex & c) const;
    complex operator*(double n ) const;
    complex operator~() const;
    
    friend complex operator*(double n , const complex & c){
        return c * n;
    }
    friend std::ostream & operator<<(std::ostream & os, const complex & c);
    friend std::istream & operator>>(std::istream & is, complex & c);
};

#endif