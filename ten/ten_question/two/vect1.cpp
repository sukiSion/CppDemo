#include <cmath>
#include "vect1.h"   // includes <iostream>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;
namespace VECTOR
{
    // compute degrees in one radian
    const double Rad_to_deg = 45.0 / atan(1.0);

    Vector::Vector(double n1, double n2 , Mode form){
         mode = form;
         if(form == RECT){
            x = n1;
            y = n2;
         }else if(form == POL){
            double mag = n1;
            double ang = n2 / Rad_to_deg;
            x = mag * cos(ang);
            y = mag * sin(ang);
         }
         else
        {
             cout << "Incorrect 3rd argument to Vector() -- ";
             cout << "vector set to 0\n";
             x = y = 0.0;
             mode = RECT;
        }
    }

    Vector::Vector()             // default constructor
    {
        x = y = 0.0;
        mode = RECT;
    }

    void Vector:: reset(double n1, double n2 , Mode form){
         
         mode = form;
         if(form == RECT){
            x = n1;
            y = n2;
         }else if(form == POL){
            double mag = n1;
            double ang = n2 / Rad_to_deg;
            x = mag * cos(ang);
            y = mag * sin(ang);
         }
         else
        {
             cout << "Incorrect 3rd argument to Vector() -- ";
             cout << "vector set to 0\n";
             x = y = 0.0;
             mode = RECT;
        }
    }

    Vector::~Vector()    // destructor
    {
    }

    void Vector::polar_mode()    // set to polar mode
    {
        mode = POL;
    }

    void Vector::rect_mode()     // set to rectangular mode
    {
        mode = RECT;
    }

    double Vector::magval() const{
        return sqrt(x * x + y * y);
    }

    double Vector::angval() const{
        if (x == 0.0 && y == 0.0)
            return 0.0;
        else
            return atan2(y, x);
    }


    // operator overloading
    // add two Vectors
    Vector Vector::operator+(const Vector & b) const
    {
        return Vector(x + b.x, y + b.y);
    }

    // subtract Vector b from a
    Vector Vector::operator-(const Vector & b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    // reverse sign of Vector
    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    // multiply vector by n
    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }

    // friend methods
    // multiply n by Vector a
    Vector operator*(double n, const Vector & a)
    {
        return a * n;
    }

    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if (v.mode == Vector::RECT)
             os << "(x,y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL)
        {
             os << "(m,a) = (" << v.magval() << ", "
                 << v.angval() * Rad_to_deg << ")";
        }
        else
             os << "Vector object mode is invalid";
        return os; 
    }
}