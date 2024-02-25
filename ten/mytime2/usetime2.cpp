#include<iostream>
#include "mytime2.h"

int main(int argc, char const *argv[])
{
    using std::cout;
    Time weeding(4 , 35);
    Time waxing(2  , 47);
    Time total;
    Time diff;
    Time adjusted;

    cout << "weeding time = ";
    weeding.Show();

    cout << "waxing Time = ";
    waxing.Show();

    cout << "total work time = ";
    total = weeding + waxing;
    total.Show();

    diff = weeding - waxing;
    cout << "weeding time - waxing time = ";
    diff.Show();

    adjusted = total * 1.5;
    cout << "adjusted wotk time = ";
    adjusted.Show();

    return 0;
}
