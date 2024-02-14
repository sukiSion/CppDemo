#include<iostream>
const int Arsize = 8;
int sum_arr(int[] , int);
int sum_arr(int arr[] , int n){
    int total = 0;
    for(int i = 0 ; i < n ; i++){
        total += arr[i];
    }
    return total;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    int cookies[Arsize]{
        1 , 2 , 4 , 8 , 16 , 32 , 64 , 128
    };
    int sum = sum_arr(cookies , Arsize);
    cout << "Total cookies eaten: " << sum << endl;
    return 0;
}
