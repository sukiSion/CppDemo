#include<iostream>
#include "sales.h"

int main(int argc, char const *argv[])
{
    using namespace SALES;
    double arr[4] =  {3.4, 5.6, 2.5, 6.1};
    Sales s2 , s1{
       arr, 4
    } ;
    s1.showSales();
    s2.showSales();
    return 0;
}