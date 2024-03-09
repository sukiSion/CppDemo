#include "cow.h"
#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    Cow cow = Cow("Sion" , "play game" , 50);
    Cow cow1;
    cout << "cow: ";
    cow.ShowCow();
    cout << "before cow1: ";
    cow1.ShowCow();
    cout << "after cow1: ";
    cow1 = cow;
    cow1.ShowCow();
    Cow cow2 = cow1;
    cout << "cow2: ";
    cow2.ShowCow();
    return 0; 
}
