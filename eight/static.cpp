#include<iostream>
#include<cstring>
const int ArSize = 30;
using namespace std;
void strcount(const char * str){
    static int total = 0;
    int count = 0;
    cout << "\"" << str << "\"" << " contains ";
    while (*str++)
    {
        count ++;
    }
    total += count;
    cout << count << " characters" << endl;
    cout << total << " characters total" << endl;
}

int main(int argc, char const *argv[])
{
    char input[ArSize];
    char next;
    cout << "Enter a line: " << endl;
    while (cin.get(input , ArSize))
    {   
        if(!strcmp("q" , input) || !strcmp("Q" , input)){
            break;
        }
        while (cin.get() != '\n');
        strcount(input);
        cout << "Enter next line (empty line to quit): " << endl;
    }
    cout << "Bye." << endl;    
    return 0;
}
