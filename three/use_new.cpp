#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    int nights = 101;
    int * pt = new int;
    *pt = 1001;
    cout << "nights value = " << nights << ": locaton = " << &nights << endl;
    cout << "int value = " << *pt << ": location = " << pt << endl;

    double * pd = new double;
    *pd = 10000001.0;
    cout << "double value = " << *pd << ": locatoion = " << pd << endl;
    cout << "locatoion of pointer pd: " << &pd << endl;
    cout << "size of pt = " << sizeof(pt) << ": size of *pt = " << sizeof(*pt) << endl;
    cout << "size of pd = " << sizeof(pd) << ": size of *pd = " << sizeof(*pd) << endl;
    return 0;
}
