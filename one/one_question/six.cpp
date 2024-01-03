#include<iostream>

double calculateAstronomicalUnits(double lightYears);

double calculateAstronomicalUnits(double lightYears){
    return lightYears * 63240;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    double lightYears;
    cout << "Enter the number of light years: ";
    cin >> lightYears;
    cout << lightYears << " light years = " << calculateAstronomicalUnits(lightYears) << " astronomical units.";
    return 0;
}
