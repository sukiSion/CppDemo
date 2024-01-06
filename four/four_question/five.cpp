#include<iostream>
 

int main(int argc, char const *argv[])
{
    using namespace std;
      const int Months = 12;
      const char * months[Months]{
        "Jan",
        "Feb",
        "Mar",
        "Apr",
        "May",
        "Jun",
        "Jul",
        "Aug",
        "Sep",
        "Oct",
        "Nov",
        "Dec"
    };
    int * sales = new int[Months];
    for(int month = 0 ; month < Months ; month ++){
        cout << "Enter " << months[month] << " sales volume: ";
        cin >> sales[month];
    }
    int totalSales = 0;
    for(int month = 0 ; month < Months ; month ++){
        cout << months[month] << ":\t" << sales[month] << endl;
        totalSales += sales[month];
    }
    cout << "total volume is " << totalSales;
    delete [] sales;
    return 0;
}
