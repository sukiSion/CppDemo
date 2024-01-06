#include<iostream>
 

int main(int argc, char const *argv[])
{
    using namespace std;
    const int Months = 12;
    const int Years = 3;
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
    int sales[Years][Months];

    for(int year = 0 ; year < Years ; year ++){
        cout << "No." << (year + 1)<< endl;
        for(int month = 0 ; month < Months ; month ++){
            cout << "Enter " << months[month] << " sales volume: ";
            cin >> sales[year][month];
        }
        cout << endl;
    }

    int totalSales;
    cout << "\t";
    for(int month = 0 ; month < Months ; month ++){
        cout << months[month] << "\t";
    }
    cout << "totle\t" << endl;
    for(int year = 0 ; year < Years ; year ++){
        cout << "No." << (year + 1) << "\t";
        int currentYearSales = 0;
        for(int month = 0 ; month < Months ; month ++){
            cout << sales[year][month] << "\t";
            totalSales += sales[year][month];
            currentYearSales += sales[year][month];
        }
        
        cout  << currentYearSales << "\t" << endl;
    }
    
    cout << "total volume is " << totalSales;
    
    return 0;
}