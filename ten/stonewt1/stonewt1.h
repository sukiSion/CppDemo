#ifndef _STONEWT1_H_
#define _STONEWT1_H_

class Stonewt{
    private:
    static const int Lbs_er_stn = 14;
    int stone;
    double pds_left;
    double pounds;
    public:
    Stonewt();
    explicit Stonewt(double lbs);
    Stonewt(int stn , double lbs);
    ~Stonewt();
    void show_lbs() const;
    void show_stn() const;
    explicit operator int() const;
    explicit operator double() const;
};

#endif