#include<iostream>
#include<cmath>

int main(int argc, char const *argv[])
{
    using namespace std;
    const auto FOOT_UNIT = 12;
    const auto M_UNIT = 0.0254;
    const auto KG_UNIT = 2.2;
    int inches, feet , pounds;
    cout << "Enter your feet: ";
    cin >> feet;
    cout << "Enter your inches: ";
    cin >> inches;
    cout << "Enter your pounds: ";
    cin >> pounds;
    int allInches = feet * FOOT_UNIT + inches;
    cout << "Your height is " << allInches << " inches." << endl;
    auto m = allInches * M_UNIT; 
    auto kg = pounds / KG_UNIT;
    cout << "Your weight is " << kg << " kg." << endl;
    cout << "Your BMI is " << kg / (m * m) << "." << endl;
    return 0;
}
