#include<new>
#include<iostream>
const int BUF = 512;
const int N = 5;
char buffer[BUF];

int main(int argc, char const *argv[])
{
    using namespace std;
    double * pd1 , * pd2;
    pd1 = new double[N];
    pd2 = new (buffer) double[N];
    for(int i = 0 ; i < N ; i ++){
        pd2[i] = pd1[i] = 1000 + 20.0 * i;
    }
    cout << "Memory addresses:" << endl;
    cout << " heap: " << pd1 << ", static: " << (void *)buffer << endl; 
    for(int i = 0 ; i < N ; i++){
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }
    cout << endl;

    cout << "Calling new and placement new a second time: " << endl;
    double *pd3 , *pd4;
    pd3 = new double[N];
    pd4 = new (buffer) double[N];
    for(int i = 0 ; i < N ; i ++){
        pd4[i] = pd3[i] = 1000 + 20.0 * i;
    }
    cout << "Memory contents:" << endl;
    for(int i = 0 ; i < N ; i++){
        cout << pd3[i] << " at " << &pd3[i] << "; ";
        cout << pd4[i] << " at " << &pd4[i] << endl;
    }
    cout << endl;

    delete [] pd1;
    pd1 = new double[N];
    pd2 = new (buffer + N * sizeof(double)) double[N];
     for(int i = 0 ; i < N ; i ++){
        pd2[i] = pd1[i] = 1000 + 20.0 * i;
    }
    cout << "Memory contents:" << endl;
    for(int i = 0 ; i < N ; i++){
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }
    cout << "Bye." << endl;
    return 0;
}
