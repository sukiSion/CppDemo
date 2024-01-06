#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "Enter number of rows: ";
    int row ;
    cin >> row;
    for(int i = 1 ; i <= row ; i ++){
        for(int j = 0 ; j < row - i ; j++){
            cout << ".";
        }
        for(int k = 0 ; k < i ; k ++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
