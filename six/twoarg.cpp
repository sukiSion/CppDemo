#include<iostream>
using namespace std;
void n_chars(char , int);
void n_chars(char c , int n){
    while (n-- > 0)
    {
        cout << c;
    }
    cout << endl;
    return;
}

int main(int argc, char const *argv[])
{
    int times;
    char ch;
    cout << "Enter a character: ";
    cin >> ch;
    while (ch != 'q')
    {
        cout << "Enter a integer: ";
        cin >> times;
        n_chars(ch , times);
        cout << "Enter another character or press the q-key to quit: ";
        cin >> ch;
    }
    cout << "The value of times is " << times << "." << endl;
    cout << "Bye" << endl;
    return 0;
}
