#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    int rats = 101;
    int & rodents = rats;
    cout << "rats = " << rats << ", rodents = " << rodents << endl;
    rodents ++;
    cout << "rats = " << rats << ", rodents = " << rodents << endl;
    cout << "rats address = " << &rats << ", rodents address = " << &rodents << endl;
    return 0;
}
