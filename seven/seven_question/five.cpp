#include<iostream>

template <class T>
T max5(T []);

template <class T>
T max5(T  ar[]){
    T max;
    for(int i = 0 ; i < 5 ; i++){
        max = ar[i] > max ? ar[i] : max;
    }
    return max;
}


int main(int argc, char const *argv[])
{
    using namespace std;
    int intArray[5] = {32, 20, 99, 256, 9};
    double doubleArray[5] = {1.2 , 2.3 , 4.5 , 32.3 , 4.3};
    cout << "max: " << max5<int>(intArray) << endl;
    cout << "max: " << max5<double>(doubleArray) << endl;
    return 0;
}
