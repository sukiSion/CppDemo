#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    int count = 0;
    int currentValue;
    do{
        cout << "Enter int value: ";
        cin >> currentValue;
        count += currentValue;
        cout << "The sum of the numbers is " << count << endl;
    }while(currentValue != 0);
    return 0;
}
