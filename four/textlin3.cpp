#include<iostream>
int main(int argc, char const *argv[])
{
    using namespace std;
    char ch;
    int count = 0;
    // cin.get(ch);
    // while(cin.fail() == false){
    //     cout << ch;
    //     ++count;
    //     cin.get(ch);
    // }
    while(cin.get(ch)){
        cout << ch;
        ++count;
    }
    cout << endl << count << " characters read" << endl;
    return 0;
}