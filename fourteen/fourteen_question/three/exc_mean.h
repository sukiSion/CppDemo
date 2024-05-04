#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_

#include<stdexcept>
#include<string>
#include<iostream>
using std::cout;
using std::endl;
using std::logic_error;
using std::string;

class bad_mean: public logic_error{
    private: 
    double v1;
    double v2;
    public:
    bad_mean(double a , double b , const string & s = "null"): logic_error(s), v1(a) , v2(b){}
    const double Val1() const { return v1; }
    const double Val2() const { return v2; }
    virtual void mesg() const{}
};

class bad_hmean: public bad_mean{
    public:
    bad_hmean(double a , double b): bad_mean(a , b){}
    void mesg() const{
        cout << "hmean(" << Val1() << ", " << Val2() << "):" << endl;
        cout << "hmean() arguments should be a != b" << endl;
    }
};

class bad_gmean: public bad_mean{
    public:
    bad_gmean(double a , double b): bad_mean(a , b){}
    void mesg() const{
        cout << "gmean(" << Val1() << ", " << Val2() << "):" << endl;
        cout << "gmean() arguments should be >= 0" << endl;
    }
};



#endif