#include<iostream>
long long factorial(unsigned int);
long long factorial(unsigned int n){
    long long factorialResult;
    if(n == 0){
        factorialResult = 1;
    }else{
        factorialResult = n * factorial(n - 1);
    }
    return factorialResult;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    int n;
    cout << "Enter value: ";
    while (cin >> n)
    {
        if(n < 0){
            break;
        }
        long long factorialResule = factorial(n);
        cout << "factorial: " << factorialResule << endl;
        cout << "Next value: ";
    }
    cout << "Done." << endl;
    
    return 0;
}
