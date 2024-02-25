#ifndef _PLORG_H_
#define _PLORG_H_

class Plorg{
    private:
    static const int Len = 20;
    char name[Len];
    int CI;
    public:
    Plorg(const char * n = "Plorga");
    void show() const;
    void updateCI(int ci);
};

#endif