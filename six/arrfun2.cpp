#include<iostream>
using namespace std;

const int Arsize = 8;
int sum_arr(int[] , int);

int sum_arr(int arr[] , int n){
    int total = 0;
    cout << arr << " = arr , " << sizeof(arr) << " = sizeof arr" << endl;
    for(int i = 0 ; i < n ; i++){
        total += arr[i];
    }
    return total;
}

int main(int argc, char const *argv[])
{
    int cookies[Arsize]{
        1 , 2 , 4 , 8 , 16 , 32 , 64 , 128
    };
    cout << cookies << " = cookies, " << sizeof(cookies) << " = sizeof cookies" << endl;
    int sum = sum_arr(cookies , Arsize);
    cout << "Total cookies eaten " << sum << " cookies." << endl;
    sum = sum_arr(cookies , 3);
    cout << "First three eaters ate " << sum << " cookies." << endl;
    sum = sum_arr(cookies + 4 , 4);
    cout << "Last four eaters ate " << sum << " cookies." << endl;
    return 0;
}
