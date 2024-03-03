#include<iostream>
#include "stonewt1.h"

Stonewt::Stonewt(){
    stone = pounds = pds_left = 0;
}

Stonewt::Stonewt(double lbs){
    stone = int(lbs) / Lbs_er_stn;
    pds_left = int(lbs) % Lbs_er_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(int stn , double lbs){
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_er_stn + lbs;
}

Stonewt::~Stonewt(){
    
}

// show weight in stones
void Stonewt::show_stn() const
{
    std::cout << stone << " stone, " << pds_left << " pounds\n";
}

// show weight in pounds
void Stonewt::show_lbs() const
{
    std::cout << pounds << " pounds\n";
}

Stonewt::operator int() const{
    return int(pounds + 0.5);
}

Stonewt::operator double() const{
    return pounds;
}