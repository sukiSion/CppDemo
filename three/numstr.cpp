#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "What year was your house built?" << endl;
    int year;
    (cin >> year).get();
    cout << "What is its street address?" << endl;
    char address[80];
    cin.getline(address , 80);
    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!" << endl;
    return 0;
}
