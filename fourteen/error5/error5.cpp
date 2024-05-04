#include "exc_mean.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class demo
{
private:
    string word;

public:
    demo(const string &str)
    {
        word = str;
        cout << "demo " << word << " created" << endl;
    }
    ~demo()
    {
        cout << "demo " << word << " destroyed" << endl;
    }
    void show() const
    {
        cout << "demo " << word << " lives!" << endl;
    }
};

double hmean(double a, double b)
{
    if (a == -b)
    {
        throw bad_hmean(a, b);
    }
    else
    {
        return 2.0 * a * b / (a + b);
    }
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
    {
        throw bad_gmean(a, b);
    }
    else
    {
        return sqrt(a * b);
    }
}

double means(double a, double b)
{
    double am, hm, gm;
    demo d2("found in means()");
    am = (a + b) / 2.0;
    try
    {
        hm = hmean(a, b);
        gm = gmean(a, b);
    }
    catch (bad_hmean &bh)
    {
        bh.mesg();
        cout << "Caught in means()" << endl;
        throw;
    }
    d2.show();
    return (am + hm + gm) / 3.0;
}

int main(int argc, char const *argv[])
{
    double x, y, z;
    {
        demo d1("found in block in main()");
        cout << "Enter two numbers: ";
        while (cin >> x >> y)
        {
            try
            {
                z = means(x, y);
                cout << "The mean mean of " << x << " and " << y << " is " << z << endl;
                cout << "Enter next pair: ";
            }
            catch (bad_hmean &bh)
            {
                bh.mesg();
                cout << "Try again.\n";
                continue;
            }
            catch (bad_gmean &bg)
            {
                cout << bg.mesg();
                cout << "Values used: " << bg.v1 << ", " << bg.v2 << endl;
                cout << "Sorry, you don't get to play any more." << endl;
                break;
            }
        }
        d1.show();
    }
    cout << "Bye!" << endl;
    return 0;
}
