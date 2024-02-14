#include<iostream>
double average(double , double);
double average(double x, double y){
    return 2.0 * x * y / (x + y);
}

int main(int argc, char const *argv[])
{
    using namespace std;
    double x , y;
    cout << "Enter value: ";
    while (cin >> x >> y){
        if(x == 0 || y == 0){
            break;
        }
        double ave = average(x , y);
        cout << "average: " << ave << endl;
        cout << "Next value: ";
    }   
    return 0;
}