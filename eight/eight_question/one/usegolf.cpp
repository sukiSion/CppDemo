#include<iostream>
#include "golf.h"

int main(int argc, char const *argv[])
{
    golf ann, andy, arrGolf[3];
    setgolf(ann, "Ann Birdfree", 24);
    showgolf(ann);
     if (setgolf(andy) == 1){
        showgolf(andy);
        handicap(andy, 20);
        std::cout << "change handicap to 20: \n";
        showgolf(andy);
     }
     int i = 0 ;
     std::cin.clear();
     while (i < 3 && setgolf(arrGolf[i]) == 1)
     {
        showgolf(arrGolf[i]); 
        i++; 
     }
     std::cout << "Bye.\n";
    return 0;
}
