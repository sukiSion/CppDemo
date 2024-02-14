#include<iostream>
template <typename T>
void Swap(T & a , T & b);
template <typename T>
void Swap(T a[] , T b[] , int n);
void Show(int a[]);
const int Lim = 8;

template <typename T>
void Swap(T & a , T & b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void Swap(T a[] , T b[] , int n){
    for(int i = 0  ; i < n ; i++){
        T temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}
void Show(int a[]){
    using namespace std;
    cout << a[0] << a[1] << "/";
    cout << a[2] << a[3] << "/";
    for (int i = 4; i < Lim; i++)
        cout << a[i];
    cout << endl;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << "." << endl;
    cout << "Using compiler-generated int swapper:" << endl;
    Swap(i,j);              // matches original template
    cout << "Now i, j = " << i << ", " << j << "." << endl;

    int d1[Lim] = {0,7,0,4,1,7,7,6};
    int d2[Lim] = {0,7,2,0,1,9,6,9};
    cout << "Original arrays:" << endl;
    Show(d1); 
    Show(d2);
    Swap(d1,d2,Lim);        // matches new template
    cout << "Swapped arrays:\n";
    Show(d1);
    Show(d2);
    return 0;
}
