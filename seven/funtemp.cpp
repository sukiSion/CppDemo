#include<iostream>
template <typename T>
void Swap(T & a , T & b);

template <typename T>
void Swap(T & a , T & b){
    T temp = a;
    a = b;
    b = temp;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    int i = 10;
    int j = 20;
    cout << "i, j = " << i << ", " << j << "." << endl;
    cout << "Using compiler-generated int swapper:" << endl;
    Swap(i,j);  // generates void Swap(int &, int &)
    cout << "Now i, j = " << i << ", " << j << "." << endl;

    double x = 24.5;
    double y = 81.7;
    cout << "x, y = " << x << ", " << y  << "." << endl;
    cout << "Using compiler-generated double swapper:" << endl;
    Swap(x,y);  // generates void Swap(double &, double &)
    cout << "Now x, y = " << x << ", " << y  << "." << endl;
    return 0;
}
