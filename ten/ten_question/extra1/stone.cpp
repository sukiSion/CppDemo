#include<iostream>
#include "stonewt.h"
using std::cout;

int main(int argc, char const *argv[])
{
    Stonewt incognito = Stonewt(10 , 8);
    incognito = incognito * 2;
    incognito.show_lbs();
    incognito.show_stn();
}