#include "winec.h"
#include<iostream>

Wine::Wine(const char *l, int y){
    label = l;
    years = y;
    years_and_bottles = Pair<ArrayInt , ArrayInt>(ArrayInt(y) , ArrayInt(y));
}


Wine::Wine(const char *l, int y, const int yr[], const int bot[]){
    label = l;
    years = y;
    years_and_bottles = PariArray(ArrayInt(yr , y) , ArrayInt(bot , y));
}


void Wine::GetBottles() {
   for(int i = 0 ; i < years; i++){
    std::cout << "Enter year: ";
    std::cin >> years_and_bottles.first()[i];
    std::cout << "Enter bottles for that year: ";
    std::cin >> years_and_bottles.second()[i];
   } 
}

const string & Wine::Label() const{
    return label;
} 

int Wine::sum() const{
    return years_and_bottles.second().sum();
}

void Wine::Show() const{
    std::cout << "Wine: " << label << std::endl;
    std::cout << "\tYear\tBottles" << std::endl;
    for(int i = 0 ; i < years; i++){
        std::cout << "\t" << years_and_bottles.first()[i] << "\t" << years_and_bottles.second()[i] << std::endl;
    }
}