#include <iostream>
#include "stone2.h"

Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn; // integer division
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()
{
}

void Stonewt::show_stn() const
{
    std::cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt::show_lbs() const
{
    std::cout << pounds << " pounds\n";
}

bool Stonewt::operator<(const Stonewt &st) const
{
    return pounds < st.pounds;
}
bool Stonewt::operator<=(const Stonewt &st) const
{
    return pounds <= st.pounds;
}
bool Stonewt::operator>(const Stonewt &st) const
{
    return pounds > st.pounds;
}
bool Stonewt::operator>=(const Stonewt &st) const
{
    return pounds >= st.pounds;
}
bool Stonewt::operator==(const Stonewt &st) const
{
    return pounds == st.pounds;
}
bool Stonewt::operator!=(const Stonewt &st) const
{
    return pounds != st.pounds;
}