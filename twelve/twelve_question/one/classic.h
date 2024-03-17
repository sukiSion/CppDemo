#ifndef CD_H_
#define CD_H_

class Cd{
    private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;
    public:
    Cd(const char * s1 ,  const char * s2 , int n , double x);
    Cd();
    virtual ~Cd(){}
    virtual void Report() const;
};

class Classic: public Cd{
    private:
    char work1[50];
    char work2[50];
    public:
    Classic(const char * w1 , const char * w2 , const char * s1 , const char * s2 , int n , double x);
    Classic();
    virtual void Report() const;
};


#endif