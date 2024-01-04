#include<iostream>


int main(int argc, char const *argv[])
{
    using namespace std;
    double miles , gasolineQuantity;
    cout << "Enter miles: ";
    cin >> miles;
    cout << "Enter gasoline quantity: ";
    cin >> gasolineQuantity;
    cout << miles / gasolineQuantity << " mpg." << endl;
    return 0;
}
