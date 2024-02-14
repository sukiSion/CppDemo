#include<iostream>
using namespace std;

const int Arsize = 8;
int sum_arr(const int * , const int *);

int sum_arr(const int * begin, const int * end){
    int total = 0;
    for(const  int * i = begin ; i <= end ; i++){
        total += *i;
    }
    return total;
}

int main(int argc, char const *argv[])
{
    int cookies[Arsize]{
        1 , 2 , 4 , 8 , 16 , 32 , 64 , 128
    };
    int sum = sum_arr(cookies , cookies + Arsize - 1);
    cout << "Total cookies eaten " << sum << " cookies." << endl;
    sum = sum_arr(cookies , cookies + 2);
    cout << "First three eaters ate " << sum << " cookies." << endl;
    sum = sum_arr(cookies + 4 , cookies + Arsize - 1);
    cout << "Last four eaters ate " << sum << " cookies." << endl;
    return 0;
}
