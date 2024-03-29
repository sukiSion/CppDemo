#include<iostream>
void swapr(int & , int &);
void swapp(int * , int *);
void swapv(int , int);
void swapr(int & a, int & b){
    int temp = a;
    a = b;
    b = temp;
}

void swapp(int * p , int * q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

void swapv(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    int wallet1 = 300;
    int wallet2 = 350;

    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using references to swap contents:\n";
    swapr(wallet1, wallet2);   // pass variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using pointers to swap contents again:\n";
    swapp(&wallet1, &wallet2); // pass addresses of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Trying to use passing by value:\n";
    swapv(wallet1, wallet2);   // pass values of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;
    return 0;
}
