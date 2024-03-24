#include<iostream>
#include "stacktp.h"

template<template<class T> class Thing , class U , class V>
class Crab{
    private:
    Thing<U> s1;
    Thing<V> s2;
    public:
    Crab(){};
    bool push(U  a , V x){return s1.push(a) && s2.push(x);}
    bool pop(U & a , V & x){return s1.pop(a) && s2.pop(x);}
};

int main(int argc, char const *argv[])
{
    using std::cout;
    using std::cin;
    using std::endl;
    Crab<Stack , int , double> neblua;
    int ni;
    double nb;
    cout << "Enter int double pairs , such as 4 3.5(0 0 to end):" << endl;
    while(cin >> ni >> nb && ni > 0 && nb > 0){
        if(!neblua.push(ni , nb)){
            break;
        }
    }
    while(neblua.pop(ni , nb)){
        cout << ni << ", " << nb << endl;
    }
    cout << "Done." << endl;
    return 0;
}
