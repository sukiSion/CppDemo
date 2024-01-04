#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    const auto MILE_UNIT = 0.6214;
    const auto GALLON_UNIT = 3.785;
    double efc, enfc;
    int exit = 1;

    while(exit != 0){
         cout << "Enter Fuel consumption(European): ";
         cin >> efc;
         auto miles = 100 * MILE_UNIT;
         auto gallons = efc / GALLON_UNIT;
         enfc = miles / gallons;
         cout << enfc << " mpg = " << efc << " L/100km" << endl; 
         cout << "Exit?: ";
         cin >> exit;
    }
    return 0;
}
