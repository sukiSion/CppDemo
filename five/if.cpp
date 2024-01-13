#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    int total = 0 ,  spaces = 0;
    char ch;
    do{
        cin.get(ch);
        if(ch == ' '){
            spaces++;
        }
        if (ch != '.')
        {
            total++;
        }
        
    }while(ch != '.');
    cout << spaces << " spaces, " << total << " characters total in sentence" << endl;
    return 0;
}
