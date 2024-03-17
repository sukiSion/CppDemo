#include "classic.h"
#include <iostream>
using namespace std;

void Bravo(const Cd &disk)
{
    disk.Report();
}

int main(int argc, char const *argv[])
{
    {
        Cd c1("Beatiles", "Capitol", 14, 35.5);
        Classic c2 = Classic("Paino Sonata in B flat", "Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
        Cd * pcd = &c1;

        cout << "Using object directly:" << endl;
        c1.Report();
        cout << endl;
        c2.Report();

        cout << endl;
        cout << "Using type cd * pointer to objects:" << endl;
        pcd->Report();
        cout << endl;
        pcd = &c2;
        pcd->Report();

        cout << endl;
        cout << "Calling a function with a Cd reference argument:" << endl;
        Bravo(c1);
        cout << endl;
        Bravo(c2);

        cout << endl;
        cout << "Testing assignment:" << endl;
        Classic copy;
        copy = c2;
        copy.Report();
    }
    return 0;
}
