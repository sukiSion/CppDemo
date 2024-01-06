#include<iostream>
const double Deposit = 100.0;

int main(int argc, char const *argv[])
{
    using namespace std;
    int year = 0;
    double cleo = Deposit, daphne = Deposit;
    while(cleo <= daphne){
        daphne += 0.10 * Deposit;
        cleo *= 1.05;
        year ++;
    }
    cout << "Cleo need " << year << " year to surpass Daphne" << endl;
    cout << "Cleo: " << cleo << ", Daphne: " << daphne << endl;
    return 0;
}
