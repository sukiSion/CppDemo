#include<iostream>
char * buildStr(char , int);
char * buildStr(char ch, int n){
    char * pstr = new char[n + 1];
    for(int i = 0 ; i < n ; i++){
        pstr[i] = ch;
    }
    pstr[n] = '\0';
    return pstr;
}


int main(int argc, char const *argv[])
{
    using namespace std;
    int times;
    char ch;
    cout << "Enter a character: ";
    cin >> ch;
    cout << "Enter an integer: ";
    cin >> times;
    char * ps = buildStr(ch , times);
    cout << ps << endl;
    delete [] ps;
    ps = buildStr('+', 20);
    cout << ps << "-DONE-" << ps << endl;
    delete [] ps;
    return 0;
}
