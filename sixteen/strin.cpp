#include<iostream>
#include<sstream>
#include<string>

int main(int argc, char const *argv[])
{
    using namespace std;
    string lit = "It was a dark and stormy day, and the full moon flowed brilliantly.";
    istringstream instr(lit);
    string word;
    while(instr >> word){
        cout << word << endl;
    }
    return 0;
}