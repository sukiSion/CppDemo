#include<iostream>
#include <iterator>
#include <algorithm>

using namespace std;

template <class T>
int reduce(T ar[], int n)
{
    sort(ar, ar + n);
    return static_cast<int>(unique(ar, ar + n) - ar);
}

template <class T>
void print_array(T ar[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    long ar[] = {1L, 2L, 4L, 8L, 6L, 6L, 4L, 2L, 4L, 6L, 5L};
    string s[] = {"vector", "set", "map", "multiset", "multimap", "set", "map", "vector"};

    cout << "Print array before sorting and removing repetitive values(long):" << endl;
    print_array(ar, 11);
    cout << "Print array before sorting and removing repetitive values(string):" << endl;
    print_array(s, 8);
    cout << "Print array after sorting and removing repetitive values(long):" << endl;
    print_array(ar, reduce(ar, 11));
    cout << "Print array after sorting and removing repetitive values(string):" << endl;
    print_array(s, reduce(s, 8));

    return 0;
}
