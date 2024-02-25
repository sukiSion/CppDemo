#ifndef _GOLF_H_
#define _GOLF_H_

class Golf{
    private:
    static const int Len = 40;
    char fullname[Len];
    int handicap;
    public:
    Golf(){fullname[0] = '\0'; handicap = 0;}
    Golf(const char * name , int hc = 0);
    int setgolf();
    void sethandicap(int hc);
    void showgolf() const;
};

#endif