#ifndef _CD_H_
#define _CD_H_

class Cd{
    private:
    char * performers;
    char * label;
    int selections;
    double playtime;
    public:
    Cd(const char * s1 ,  const char * s2 , int n , double x);
    Cd();
    Cd(const Cd & d);
    virtual ~Cd();
    virtual void Report() const;
    virtual Cd & operator=(const Cd & d);
};

class Classic: public Cd{
    private:
    char * work1;
    char * work2;
    public:
    Classic(const char * w1 , const char * w2 ,  const char * s1 ,  const char * s2 , int n , double x);
    Classic();
    Classic(const Classic & c);
    virtual ~Classic();
    virtual void Report() const;
    Classic & operator=(const Classic & c);
};

#endif