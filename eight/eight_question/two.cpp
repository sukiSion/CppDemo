#include<iostream>
#include<string>
using namespace std;
void strcount(const string & str){
    static int total = 0;
    int count = str.size();
    total += count;
    cout << "\"" << str << "\"" << " contains ";
    cout << count << " characters" << endl;
    cout << total << " characters total" << endl;
}

int main(int argc, char const *argv[])
{
    string input;
    cout << "Enter a line: " << endl;
    while (getline(cin , input))
    {   
        if(input == "" || input == "q" || input == "Q"){
            break;
        }
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
    }
    cout << "Bye." << endl;    
    return 0;
}
