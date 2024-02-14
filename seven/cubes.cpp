#include<iostream>
double cube(double a);
double refcube(double & a);
double refcube(double & ra){
    ra *= ra * ra;
    return ra;
}

double cube(double a){
    a *= a * a;
    return a;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    double x = 3.0;

    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(x);
    cout << " = cube of " << x << endl;
    return 0;
}
