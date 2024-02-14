#include<iostream>
#include<array>
#include<string>
using namespace std;
const int Seasons = 4;
const char * Snames[Seasons]{
    "Spring",
    "Summer",
    "Fall",
    "Winter"
};
void fill(double [] , int);
void show(const double [] , int);

void fill(double expenses[] , int n){
    for(int i = 0 ; i < n ; i++){
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> expenses[i];
    }
}

void show(const double expenses[] , int n){
    double total = 0.0;
    cout << "EXPENSES" << endl;
    for(int i = 0 ; i < n ; i++){
        cout << Snames[i] << ": $" << expenses[i] << endl;
        total += expenses[i];
    }
    cout << "Total Expenses: $" << total << endl;
}

int main(int argc, char const *argv[])
{
    double expenses[Seasons];
    fill(expenses , Seasons);
    show(expenses , Seasons);
    return 0;
}

