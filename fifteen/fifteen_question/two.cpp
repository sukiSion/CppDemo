#include<string>
#include<iostream>
#include<algorithm>
#include<cctype>
using namespace std;

bool IsSpaceOrPunct(char ch){
    return isspace(ch) || ispunct(ch);
}

string ToLower(string & st)
{
    string s;
    for (auto &x : st) {
        if(IsSpaceOrPunct(x)){
            continue;
        }
        s += tolower(x);
    }
    return s;
}

int main(int argc, char const *argv[])
{
    cout << "Please enter a string (quit to quit): ";
    string word;
    while(getline(cin , word) && word != "quit"){
        cout << "\"" << word << "\"";
        word = ToLower(word);
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


