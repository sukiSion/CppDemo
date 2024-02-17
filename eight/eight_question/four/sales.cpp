#include<iostream>
#include "sales.h"

namespace SALES{
    void setSales(Sales & s , const double ar[] , int n){
        double total = 0;
        double max = ar[0];
        double min = ar[0];
        for(int i = 0 ; i < n ; i ++){
             max = ar[i] > max ? ar[i] : max;
             min = ar[i] < min ? ar[i] : min;
             s.sales[i] = ar[i];
             total += ar[i];
        }
        s.max = max;
        s.min = min;
        s.average = total / n;       
    }

    void setSales(Sales & s){
        using std::cout;
        using std::cin;
        double sales[QUARTERS];
        int i = 0;
        while (i < QUARTERS && cin >> sales[i] )
        {
            i++;
        }
        
        if(i != 0){
             setSales(s , sales , i);    
        }    
    }

    void showSales(const Sales & s){
        using std::cout;
        using std::endl;
        cout << "Display all information in sales : " << endl;
        cout << "The 4 quarters are $" << s.sales[0] << ", $" << s.sales[1] << ", $" << s.sales[2] << ", $" << s.sales[3] << endl;
        cout << "The average income is $" << s.average << endl;
        cout << "The maximum income is $" << s.max << endl;
        cout << "The minimum income is $" << s.min << endl;
    }
}