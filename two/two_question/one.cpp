#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    const auto FOOT_UNIT = 12;
    int inch;
    cout << "Enter your height(inches): ___\b\b\b";
    cin >> inch;
    cout << "your height is " << inch / FOOT_UNIT << " feet " << inch % FOOT_UNIT << " inches." << endl;   
    return 0;
}
