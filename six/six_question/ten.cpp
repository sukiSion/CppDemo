#include <iostream>

double add(double, double);
double reduce(double, double);
double multiply(double, double);
double divide(double, double);
double calculate(double, double, double (*)(double, double));

double add(double x, double y)
{
    return x + y;
}

double reduce(double x, double y)
{
    return x - y;
}
double multiply(double x, double y)
{
    return x * y;
}
double divide(double x, double y)
{
    return x / y;
}

double calculate(double x, double y, double (*opera)(double, double))
{
    return (*opera)(x, y);
}

int main(int argc, char const *argv[])
{
    using namespace std;
    double (*pf[4])(double, double){
        add,
        reduce,
        multiply,
        divide};
    double x, y;
    cout << "Enter x and y: ";
    while (cin >> x >> y)
    {
        for (int i = 0; i < 4; i++)
        {
            cout << (*pf[i])(x, y) << endl;
        }
        cout << "Nect x and y: ";
    }
    cout << "Done." << endl;
    return 0;
}
