#include <iostream>
#include "sales.h"
using namespace SALES;

Sales::Sales(const double ar[], int n)
{
    n = n > QUARTERS ? QUARTERS : n;
    double total = 0;
    min = ar[0];
    max = ar[0];
    for (int i = 0; i < n; i++)
    {
        double arValue = ar[i];
        sales[i] = arValue;
        total += arValue;
        min = min < arValue ? min : arValue;
        max = max > arValue ? max : arValue;
    }
    average = total / QUARTERS;
}

void Sales::showSales() const
{
    using std::cout;
    using std::endl;
    cout << "Display all information in sales : " << endl;
    cout << "The 4 quarters are $" << sales[0] << ", $" << sales[1] << ", $" << sales[2] << ", $" << sales[3] << endl;
    cout << "The average income is $" << average << endl;
    cout << "The maximum income is $" << max << endl;
    cout << "The minimum income is $" << min << endl;
}
