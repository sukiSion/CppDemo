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
struct expense{
    double expenses[Seasons];
};
void fill(expense * , int);
void show(const expense , int);

void fill(expense * e , int n){
    for(int i = 0 ; i < n ; i++){
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> e->expenses[i];
    }
}

void show(const expense e , int n){
    double total = 0.0;
    cout << "EXPENSES" << endl;
    for(int i = 0 ; i < n ; i++){
        cout << Snames[i] << ": $" << e.expenses[i] << endl;
        total += e.expenses[i];
    }
    cout << "Total Expenses: $" << total << endl;
}

int main(int argc, char const *argv[])
{
    expense e;
    fill(&e , Seasons);
    show(e , Seasons);
    return 0;
}

