#ifndef WINEC_H_
#define WINEC_H_

#include<string>
#include<valarray>

using std::string;
using std::valarray;

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

typedef valarray<int> IntArray;
typedef Pair<IntArray , IntArray> ArrayPair;

class Wine: private string ,  private ArrayPair{
    private:
    int years;
    public:
    Wine(const char *l, int y): string(l) , ArrayPair(IntArray(y) , IntArray(y)){
        years = y;
    }
    Wine(const char *l, int y, const int yr[], const int bot[]): string(l) , ArrayPair(IntArray(yr , y) , IntArray(bot , y)){
        years = y;
    } 
    virtual ~Wine(){}
    void GetBottles();
    const string &Label() const;
    int sum() const;
    void Show() const;    
};

#endif