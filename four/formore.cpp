#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    const auto SIZE = 16;
    long long factorials[SIZE]{1};
    for(int i = 1 ; i < SIZE; i++){
        factorials[i] = factorials[i - 1] * i;
    }
    for(int i = 0 ; i < SIZE ; i++){
       cout << i << "! = " << factorials[i] << endl; 
    }
    return 0;
}
