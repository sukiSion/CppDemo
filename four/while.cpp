#include<iostream>
#include<string>
const int ArSize = 20;

int main(int argc, char const *argv[])
{
    using namespace std;
    string name;
    cout << "Your first name, please: " ;
    cin >> name;
    cout << "Here is your name , verticalized and ASCIIized: " << endl;
    int i = 0;
    do{
        cout << name[i] << ": " << static_cast<int>(name[i]) << endl;
        i++;
    }while(name[i] != '\0');

    return 0;
}