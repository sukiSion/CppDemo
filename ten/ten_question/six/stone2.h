// stonewt.h -- definition for the Stonewt class
#ifndef _STONE2_H_
#define _STONE2_H_
class Stonewt
{
private:
    enum {Lbs_per_stn = 14};      
    int stone;                    
    double pds_left;              
    double pounds;                
public:
    Stonewt(double lbs);          
    Stonewt(int stn, double lbs); 
    Stonewt();                    
    ~Stonewt();
    void show_lbs() const;        
    void show_stn() const;
    bool operator<(const Stonewt & st) const;
    bool operator<=(const Stonewt & st) const;
    bool operator>(const Stonewt & st) const;
    bool operator>=(const Stonewt & st) const;
    bool operator==(const Stonewt & st) const;
    bool operator!=(const Stonewt & st) const;         
};
#endif