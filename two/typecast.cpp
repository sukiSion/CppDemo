#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    int auks , bats , coots;
    auks = 11.99 + 19.99;
    bats = (int)11.99 + (int)19.99;
    coots = int(11.99) + int(19.99);
    cout << "auks = " << auks << ", bats = " << bats << ", coots = " << coots << endl;
    char ch = 'Z';
    cout << "The code for " << ch << " is " << int(ch) << endl;
    cout << "Yes , the code is " << static_cast<int>(ch) << endl;
    return 0;
}
