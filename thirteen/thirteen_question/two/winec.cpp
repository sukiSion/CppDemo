#include "winec.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void Wine::GetBottles(){
    for(int i = 0 ; i < years; i++){
    std::cout << "Enter year: ";
    std::cin >> ArrayPair::first()[i];
    std::cout << "Enter bottles for that year: ";
    std::cin >> ArrayPair::second()[i];
   }
}

const string & Wine::Label() const{
    return static_cast<const string &>(*this);
}

int Wine::sum() const{
    return ArrayPair::second().sum();
}

void Wine::Show() const{
    std::cout << "Wine: " << Label() << std::endl;
    std::cout << "\tYear\tBottles" << std::endl;
    for(int i = 0 ; i < years; i++){
        std::cout << "\t" << ArrayPair::first()[i] << "\t" << ArrayPair::second()[i] << std::endl;
    }
}