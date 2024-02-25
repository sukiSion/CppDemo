#include<iostream>
#include "plorg.h"

int main(int argc, char const *argv[])
{
    Plorg plorg("Sion");
    plorg.show();
    plorg.updateCI(100);
    plorg.show();
    return 0;
}
