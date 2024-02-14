#include<iostream>
#include<string>
#include <cctype>
using namespace std;
void toUpperStr(string & str){
    for(int i = 0 ; i < str.length() ; i++){
        str[i] = toupper(str[i]);
    }
    cout << str << endl;
}


int main(int argc, char const *argv[])
{
    cout << "Enter a string (q to quit): ";
    string str;
    while (getline(cin , str))
    {
        if(str == "q" || str == "Q"){
            break;
        }
        toUpperStr(str);
        cout << "Next string (q to quit):";
    }
    cout << "Bye." << endl;
    return 0;
}
