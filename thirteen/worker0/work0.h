#ifndef _WORK0_H_
#define _WORK0_H_

#include<string>
class Worker{
    std::string fullname;
    long id;
    public:
    Worker(): fullname("no one") , id(0L){}
    Worker(const std::string & s , long n): fullname(s) , id(n){}
    virtual ~Worker() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

class Waiter: public Worker{
    private:
    int panache;
    public:
    Waiter(): Worker() , panache(0){}
    Waiter(const std::string & s , long n , int p = 0):
    Worker(s , n) , panache(){}
    Waiter(const Worker & wk , int p = 0):
    Worker(wk) , panache(p){}
    void Set();
    void Show() const;
};

class Singer: public Worker{
    protected:
    enum {
        other,
        alto,
        contralto,
        soprano,
        bass,
        baritone,
        tenor
    };
    static const int Vtypes = 7;
    private:
    int voice;
    static const char * pv[Vtypes];
    public:
    Singer(): Worker() , voice(other){}
    Singer(const std::string & s , long n , int v = other):Worker(s , n) , voice(v){}
    Singer(const Worker & wk , int v = other): Worker(wk) , voice(v){}
    void Set();
    void Show() const;
};

#endif