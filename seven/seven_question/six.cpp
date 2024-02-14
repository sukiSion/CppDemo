#include<iostream>
#include <cstring>
using namespace std;
template <class T>
T maxn(T [] , int);

template <class T>
T maxn(T ar[] , int n){
    T max;
    for(int i = 0 ; i < n ; i++){
        max = ar[i] > max ? ar[i] : max;
    }
    return max;
}

template <>
const char * maxn<const char *>(const char * [] , int );
template <>
const char * maxn<const char *>(const char * ch[] , int n){
    const char * maxCh;
    int maxLength;
    for(int i = 0 ; i < n ; i++){
        if(strlen(ch[i]) > maxLength){
            maxLength = strlen(ch[i]);
            maxCh = ch[i];
        }
    }
    return maxCh;
}

int main(int argc, char const *argv[])
{
    int	intArray[] = {32, -1, 99, 0, 256, 9};
    double	doubleArray[] = {-3.2, 221.22, 9.9, 0.1};
    const char*	charArray[] = {"aaaa","bbbbbb","cc","fffffffffff","kkkk"};
    cout << "max: " << maxn<int>(intArray , 6) << endl;
    cout << "max: " << maxn<double>(doubleArray , 4) << endl;
    cout << "max: " << maxn(charArray , 5) << endl;
    return 0;
}
