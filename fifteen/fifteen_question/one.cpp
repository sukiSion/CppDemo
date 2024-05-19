#include<string>
#include<iostream>
#include<algorithm>

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "Please enter a string (quit to quit): ";
    string word;
    while(getline(cin , word) && word != "quit"){
        cout << "\"" << word << "\"";
        if(word == string(word.rbegin() , word.rend())){
            cout << " is ";
        }else{
            cout << " isn't ";
        }
        cout << "a palindrome string." << endl;
        cout << "You can enter again (quit to quit): ";
    }
    cout << "Done." << endl;
    return 0;
}
