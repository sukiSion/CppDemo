#include<iostream>
#include<cmath>

int main(int argc, char const *argv[])
{
    using namespace std;
    double area;
    cout << "Enter the floor area, in square feet, or your home: " << endl;
    cin >> area;
    double side = sqrt(area);
    cout << "That's the equivalent of a square " << side << " feet to the side. " << endl;
    cout << "How fascinating!" << endl; 
    return 0;
}
