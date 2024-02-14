#include<iostream>
using namespace std;
const int SIZE = 10;
int Fill_array(double [] , int);
void Show_array(const double [] , int);
void Reverse_array(double [] , int);

int Fill_array(double ar[] , int n){
    int length = 0;
    double temp;
    cout << "Enter value(q to quit): " << endl;
    while(length < n && cin >> temp ){
        ar[length] = temp;
        length++;
    }
    return length;
}

void Show_array(const double ar[] , int n){
    cout << "array: [ ";
    for(int i = 0 ; i < n ; i++){
        cout << ar[i]  ;
        if(i < n - 1){
            cout << " , ";
        }
    }
    cout << " ]" << endl;
}

void Reverse_array(double ar[] , int n){
    for(int i = 0 ; i < n / 2 ; i ++){
        double temp = ar[n - i - 1];
        ar[n - i - 1] = ar[i];
        ar[i] = temp;
    }
}


int main(int argc, char const *argv[])
{
    using namespace std;
    double ar[SIZE];
    int length = Fill_array(ar , SIZE);
    if(length > 0){
        Show_array(ar , length);
        Reverse_array(ar , length);
        Show_array(ar , length);
    }else{
        cout << "No Data." << endl;
    }
    cout << "Done." << endl;
    return 0;
}
