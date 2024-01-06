#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    int min , max;
    cout << "Enter minimun: " ;
    cin >> min;
    cout << "Enter maximum: " ;
    cin >> max;
    int count = 0;
    for(int i = min ; i <= max ; i++){
        count += i;
    }
    cout << "The sum of the numbers is " << count << endl;
    return 0;
}
