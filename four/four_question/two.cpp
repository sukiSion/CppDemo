#include<iostream>
#include<array>

const int ArSize = 100;

int main(int argc, char const *argv[])
{
    using namespace std;
    array<long double , ArSize> factorials{1};
    for(int i = 1 ; i < ArSize ; i++){
        factorials[i] = factorials[i - 1] * i;
    }
    for(int i = 0 ; i <= ArSize ; i++){
       cout << i << "! = " << factorials[i] << endl; 
    }
    return 0;
}
