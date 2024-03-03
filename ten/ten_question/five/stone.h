#ifndef _STONE_H_
#define _STONE_H_

#include<iostream>

class Stonewt{
    public:
    enum Mode{STONE , INT_POUND , DOUBLE_POUND};
    private:
    static const int Lbs_er_stn = 14;
    int stone;
    double pds_left;
    double pounds;
    Mode mode;
    public:
    Stonewt();
    Stonewt(double lbs , Mode form = STONE);
    Stonewt(int stn , double lbs , Mode form = STONE);
    ~Stonewt();
    void setMode(Mode form);
    Stonewt operator+(const Stonewt & st) const;
    Stonewt operator-(const Stonewt & st) const;
    Stonewt operator*(double n) const;
    friend Stonewt operator*(double n, const Stonewt & st)
    {
        return st * n;
    }
    friend std::ostream & operator<<(std::ostream & os, const Stonewt & st);
};

#endif