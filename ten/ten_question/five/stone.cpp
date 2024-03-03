#include "stone.h"

Stonewt::Stonewt(){
    pounds = stone = pds_left = 0;
    mode = STONE;
}

Stonewt::Stonewt(double lbs , Mode form ){
    mode = form;
    stone = int(lbs) / Lbs_er_stn;
    pds_left = int(lbs) % Lbs_er_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(int stn , double lbs , Mode form ){
    mode = form;
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_er_stn + lbs;
}

Stonewt::~Stonewt(){
    
}

void Stonewt::setMode(Mode form){
    mode = form;
}

Stonewt Stonewt::operator+(const Stonewt & st) const{
    return Stonewt(pounds + st.pounds);
}

Stonewt Stonewt::operator-(const Stonewt & st) const{
    return Stonewt(pounds - st.pounds);
}

Stonewt Stonewt::operator*(double n) const{
    return Stonewt(n * pounds);
}

std::ostream & operator<<(std::ostream & os, const Stonewt & st){
    if(st.mode == Stonewt::Mode::STONE){
        std::cout << st.stone << " stone, " << st.pds_left << " pounds\n";
    }else if(st.mode == Stonewt::Mode::DOUBLE_POUND){
        std::cout << double(st.pounds) << " pounds\n";
    }else if(st.mode == Stonewt::Mode::INT_POUND){
        std::cout << int(st.pounds) << " pounds\n";
    }
    return os;
}
