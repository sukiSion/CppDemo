#include<iostream>
#include<string>
using namespace std;
const int SIZE = 5;
void display(const string *  , int);
void display(const string * sa , int n){
    while (--n >= 0)
    {
        cout << sa[n] << endl;
    }
}

int main(int argc, char const *argv[])
{
    string list[SIZE];
    cout << "Enter your " << SIZE << " favorite astronomical sights:" << endl;
    for(int i = 0 ; i < SIZE ; i ++){
        cout << i + 1 << ": ";
        getline(cin , list[i]);
    }
    cout << "Your list: " << endl;
    display(list , SIZE);
    return 0;
}
