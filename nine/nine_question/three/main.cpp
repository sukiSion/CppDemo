#include<iostream>
#include "golf.h"

int main(int argc, char const *argv[])
{
    Golf golf("Ann Birdfree", 24);
    golf.showgolf();
    Golf golf1;
    if (golf1.setgolf() == 1){
        golf1.showgolf();
        golf1.sethandicap(20);
        golf1.showgolf();
     }
     std::cout << "Bye.\n";
    return 0;
}