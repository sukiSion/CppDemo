#include<iostream>
#include<climits>
bool is_int(double);

bool is_int(double x){
    return x <= INT_MAX && x >= INT_MIN;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    double num;
    cout << "Yo, dube! Enter an integer value: ";
    cin >> num;
    while (!is_int(num))
    {
        cout << "Out of range -- please try again: ";
        cin >> num;
    }
    int val = int(num);
    cout << "You've entered the integer " << val << endl << "Bye" << endl;
    return 0;
}
