#include<iostream>
#include "port.h"

int main(int argc, char const *argv[])
{
    Port port("Gallo" , "tawny" , 20);
    VintagePort vintagePort("Gallo" , 20 , "The Noble" , 1970);
    port.Show();
    vintagePort.Show();
    return 0;
}
