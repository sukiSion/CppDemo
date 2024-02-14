#include <iostream>
using namespace std;
struct debts
{
    char name[50];
    double amount;
};

template <class T>
T SumArray(T arr[], int n);

template <class T>
T SumArray(T arr[], int n)
{
    T sum;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

template <class T>
T SumArray(T *arr[], int n);
template <class T>
T SumArray(T *arr[], int n)
{
    T sum;
    for (int i = 0; i < n; i++)
    {
        sum += *arr[i];
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int things[6] = {13, 31, 103, 301, 310, 130};
    debts mr_E[3]{
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}};
    double *pd[3];
    for (int i = 0; i < 3; i++)
    {
        pd[i] = &mr_E[i].amount;
    }
    cout << "Listing Mr. E's counts of things: " << SumArray(things, 6) << endl;
    cout << "Listing Mr. E's debts: " << SumArray(pd, 3) << endl;

    return 0;
}