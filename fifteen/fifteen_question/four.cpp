#include<iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int reduce(long ar[] , int n){
    sort(ar , ar + n);
    return static_cast<int>(unique(ar , ar + n) - ar);
}

void print_array(long ar[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}



int main(void)
{
    long ar[] = {1L, 2L, 4L, 8L, 6L, 6L, 4L, 2L, 4L, 6L, 5L};

    cout << "Print array before sorting and removing repetitive values:" << endl;
    print_array(ar, 11);
    cout << "Print array after sorting and removing repetitive values:" << endl;
    print_array(ar, reduce(ar, 11));

    return 0;
}