#include<iostream>
using namespace std;
void oil(int x){
    int texas = 5;
    cout << "In oil() , texa = " << texas << ", &texas = " << &texas << endl;
    cout << "In oil() , x = " << x << ", &x = " << &x << endl;
    {
        int texas = 113;
        cout << "In block, texas = " << texas << ", &texas = " << &texas << endl;
        cout << "In block , x = " << x << ", &x = " << &x << endl;
    }
    cout << "Post-block texas = " << texas << ", &texas = " << &texas << endl;
}

int main(int argc, char const *argv[])
{
    int texas = 31;
    int year = 2011;
    cout << "In main(), texas = " << texas << ", &texas = " << &texas << endl;
    cout << "In main(), year = " << year << ", &year = " << &year << endl;
    oil(texas);
    cout << "In main(), texas = " << texas << ", &texas = " << &texas << endl;
    cout << "In main(), year = " << year << ", &year = " << &year << endl;
    return 0;
}
