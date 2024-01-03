#include<iostream>
double calculateFahrenheitDegrees(double celsiusDegrees);

double calculateFahrenheitDegrees(double celsiusDegrees){
    return 1.8 * celsiusDegrees + 32.0;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    double celsiusDegrees;
    cout << "Please enter a Celsius value: ";
    cin >> celsiusDegrees;
    double fahrenheitDegrees = calculateFahrenheitDegrees(celsiusDegrees);
    cout << celsiusDegrees << " degrees Celsius is " << fahrenheitDegrees << " degrees Fahrenheit.";
    return 0;
}
