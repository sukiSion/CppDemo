#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    int income;
    while (cin >> income && income >= 0)
    {
        cout << "personals = ";
        if(income <= 5000){
             cout << 0 << endl;
        }else if (income > 5000 && income <= 15000)
        {
            cout << 5000 * 0.00 + (income - 5000) * 0.10 << endl;
        }else if (income > 15000  && income <= 35000)
        {
            cout << 5000 * 0.00 + 10000 * 0.10 + (income - 15000) * 0.15 << endl;
        }else if (income > 35000)
        {
            cout << 5000 * 0.00 + 10000 * 0.10 + 20000 * 0.15 + (income - 35000) * 0.20 << endl;
        } 
    }
    cout << "Done!";
    return 0;
}
