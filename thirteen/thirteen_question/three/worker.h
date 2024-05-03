#ifndef _WORKER_H_
#define _WORKER_H_

#include<string>
using std::string;

class Worker{
    private:
    string fullname;
    long id;
    public:
    Worker(): fullname("no one") , id(0L){}
    Worker(const string & s , long n): fullname(s) , id(n){}
    virtual ~Worker(){}
    void Set();
    void Show() const;
};

#endif