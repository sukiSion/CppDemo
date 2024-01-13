#include<iostream>
const int ArSize = 80;

int main(int argc, char const *argv[])
{
    using namespace std;
    char line[ArSize];
    int spaces = 0;
    cout << "Enter a line of text: " << endl;
    cin.get(line , ArSize);
    cout << "Complete line:" << endl << line << endl;
    cout << "Line through first period:" << endl;
    for(int i = 0 ; line[i] != '\0'; i++){
        cout << line[i];
        if(line[i] == '.'){
            break;
        }
        if(line[i] != ' '){
            continue;
        }
        spaces++;
    } 
    cout << endl << spaces << " spaces" << endl << "Done." << endl;
    return 0; 
}
