#include<iostream>
using namespace std;
template <typename T>
void ShowArray(T arr[] , int n );

// template <typename T>
// void ShowArray(T *arr[] , int n );

template <typename T>
void ShowArray(T arr[] , int n ){
    cout << "template A" << endl;
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}

// template <typename T>
// void ShowArray(T *arr[] , int n ){
//     cout << "template B" << endl;
//     for(int i = 0 ; i < n ; i++){
//         cout << *arr[i] << " " ;
//     }
//     cout << endl;
// }

struct debts
{
    char name[50];
    double amount;
};

int main(int argc, char const *argv[])
{
    int things[6] = {13  , 31 , 103 , 301 , 310 , 130};
    debts mr_E[3]{
        {"Ima Wolfe" , 2400.0},
        {"Ura Foxe" , 1300.0},
        {"Iby Stout" , 1800.0}
    };
    double * pd[3];
    for(int i = 0 ; i < 3 ; i++){
        pd[i] = &mr_E[i].amount;
    }
    cout << "Listing Mr. E's counts of things:" << endl;
    ShowArray(things, 6);  // uses template A
    cout << "Listing Mr. E's debts:" << endl;
    ShowArray(pd, 3);   
    return 0;
}

