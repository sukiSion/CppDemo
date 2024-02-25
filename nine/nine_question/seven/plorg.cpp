#include "plorg.h"
#include<iostream>
#include<cstring>

Plorg::Plorg(const char * n){
    strncpy(name , n , Len - 1);
    name[Len - 1] = '\0';
    CI = 50;
}

void Plorg::show() const{
    using std::cout;
    using std::endl;
    cout << "name: " << name << ", CI: " << CI << endl;
}

void Plorg::updateCI(int ci){
    CI = ci;
}