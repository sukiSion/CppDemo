#ifndef _ARRAYTP_H_
#define _ARRAYTP_H_
#include<iostream>
#include<cstdlib>

template<class T , int n>
class ArratTP{
    private:
    T ar[n];
    public:
    ArratTP(){};
    explicit ArratTP(const T & v);
    virtual T & operator[](int i);
    virtual T operator[](int i) const;
};

template<class T , int n>
ArratTP<T,n>::ArratTP(const T & v) {
    for(int i = 0 ; i < n ; i++){
        ar[i] = v;
    }
}

template<class T , int n>
T & ArratTP<T,n>::operator[](int i){
    if(i < 0 || i >= n){
        std::cerr << "Error in array limits: " << i << " is out of range" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

template<class T , int n>
T  ArratTP<T,n>::operator[](int i) const{
    if(i < 0 || i >= n){
        std::cerr << "Error in array limits: " << i << " is out of range" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

#endif