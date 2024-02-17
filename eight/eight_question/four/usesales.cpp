#include<iostream>
#include "sales.h"

int main(int argc, char const *argv[])
{
    using namespace SALES;
    double arr[4] = {3.4, 5.6, 2.5, 6.1};
    Sales s1, s2;
    setSales(s1, arr, 4);
    showSales(s1);
    setSales(s2);
    showSales(s2);
    return 0;
}
