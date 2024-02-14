#include<iostream>
using namespace std;
struct job
{
    char name[40];
    double salary;
    int floor;
};


template <typename T>
void Swap(T & a , T & b);

template void Swap<int>(int & , int &);

template <> void Swap<job>(job & j1 , job & j2);
void Show(const job & j);

template <typename T>
void Swap(T & a , T & b){
    T temp = a;
    a = b;
    b = temp;
}

template <> void Swap<job>(job & j1 , job & j2){
    double t1 = j1.salary;
    int t2 = j1.floor;
    j1.salary = j2.salary;
    j1.floor = j2.floor;
    j2.salary = t1;
    j2.floor = t2;
}

void Show(const job & j){
    cout << j.name << ": $" << j.salary
         << " on floor " << j.floor << endl;
}

int main(int argc, char const *argv[])
{
    cout.precision(3);
    cout.setf(ios::fixed, ios::floatfield);
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << "." << endl;
    cout << "Using compiler-generated int swapper:" << endl;
    Swap(i,j);    // generates void Swap(int &, int &)
    cout << "Now i, j = " << i << ", " << j << "." << endl;
    job sue = {"Susan Yaffee", 73000.60, 7};
    job sidney = {"Sidney Taffee", 78060.72, 9};
    cout << "Before job swapping:" << endl;
    Show(sue);
    Show(sidney);
    Swap(sue, sidney); // uses void Swap(job &, job &)
    cout << "After job swapping:" << endl;
    Show(sue);
    Show(sidney);
    return 0;
}

