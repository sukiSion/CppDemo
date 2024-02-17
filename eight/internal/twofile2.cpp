#include<iostream>
extern int tom;
static int dick = 10;
int harry = 200;

void remote_access(){
    using namespace std;
    cout << "main() reports the following address: " << endl;
    cout << &tom << " = &tom, " << &dick << "  = &dick, " << &harry << " = &harry" << endl;
}