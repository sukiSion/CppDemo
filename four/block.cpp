#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "The Amazing Accounto will sum and average five numbers for you." << endl;
    cout << "Please enter five values:" << endl;
    int sum = 0;
    for(int i = 1; i <= 5 ; i++){
        cout << "Value " << i << ": " ;
        int number;
        cin >> number;
        sum += number;
    } 
    cout << "Five exquisite choices indeed! They sum to " << sum ;
    cout << " and average to " << sum / 5.0 << "." << endl;
    cout << "The Amazing Accounto bids you adieu!" << endl;
    return 0;
}
