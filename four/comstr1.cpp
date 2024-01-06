#include<iostream>
#include<cstring>

int main(int argc, char const *argv[])
{
    using namespace std;
    char word[] = "?ate";
    for(char i = 'a' ; strcmp(word , "mate") ; i++){
        cout << word << endl;
        word[0] = i;
    }
    cout << "After loop ends , word is " << word << endl;
    return 0;
}
