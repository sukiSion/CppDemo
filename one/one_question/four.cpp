#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    int age;
    cout << "Enter you age: ";
    cin >> age;
    cout << "Your age in months is " << age * 12 << "." <<endl;
    return 0;
}