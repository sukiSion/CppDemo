#include<iostream>
int main(int argc, char const *argv[])
{
    using namespace std;
    char ch;
    int count = 0;
    cout << "Enter characters; enter # to quit: "<< endl;
    cin >> ch;
    while(ch != '#'){
        cout << ch;
        ++count;
        cin >> ch;
    }
    cout << endl << count << " characters read" << endl;
    return 0;
}
