#include<iostream>
#include<cctype>

int main(int argc, char const *argv[])
{
    using namespace std;
    char ch;
    cout << "Please Enter: " << endl;
    while (cin.get(ch) && ch != '@'){
         if(!isdigit(ch)){
            if(islower(ch)){
                cout << static_cast<char>(toupper(ch));
            }else if(isupper(ch)){
                cout << static_cast<char>(tolower(ch));
            }else {
                cout << ch;
            }
         }
    }
    
    return 0;
}
