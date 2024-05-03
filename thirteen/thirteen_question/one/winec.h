#ifndef WINEC_H_
#define WINEC_H_

#include<string>
#include<valarray>

template<class T , class R>
class Pair{
    private:
    T a;
    R b;
    public:
    Pair(){}
    Pair(const T & first , const R & second): a(first) , b(second){}
    T & first(){return a;}
    R & second() {return b;}
    T first() const{return a;}
    R second() const{return b;}
    
};
using std::string;
using std::valarray;
typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt , ArrayInt> PariArray;


class Wine{
    private:
    string label;
    int years;
    PariArray years_and_bottles;
    public:
    Wine(const char *l, int y);
    Wine(const char *l, int y, const int yr[], const int bot[]);
    virtual ~Wine(){}
    void GetBottles();
    const string &Label() const;
    int sum() const;
    void Show() const;
};

#endif