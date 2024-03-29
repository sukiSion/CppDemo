#include<iostream>
#include "string1.h"
const int ArSize = 10;
const int MaxLen = 81;

int main(int argc, char const *argv[])
{
    using std::cout;
    using std::cin;
    using std::endl;
    String name;
    cout << "Hi , what's your name?" << endl;
    cin >> name;
    cout << name << ", please enter up to " << ArSize << " short sayings <empty line to quit>:" << endl;
    char temp[MaxLen];
    int i;
    String sayings[ArSize];
    for(i = 0 ; i < ArSize ; i++){
        cout << i + 1 << ": ";
        cin.get(temp , MaxLen);
        while (cin && cin.get() != '\n');
        if(!cin || (temp[0] == '\0')){
            break;
        }else{
            sayings[i] = temp;
        }
    }
    int total = i;
    if(total > 0){
        cout << "Here are your sayings: " << endl;
        for(i = 0 ; i < total ; i++){
            cout <<  sayings[i][0] << ": " << sayings[i] << endl;
        }
        int shortest = 0;
        int first = 0;
        for(i = 0 ; i < total ; i++){
            if(sayings[i].length() < sayings[shortest].length()){
                shortest = i;
            }
            if(sayings[i] < sayings[first]){
                first = i;
            }
        }
        cout << "Shortest saying: " << endl;
        cout << sayings[shortest] << endl;
        cout << "First alphabetically: " << endl;
        cout << sayings[first] << endl;
        cout << "This program used " << String::HowMany() << " String objects. Bye." << endl;
    }else{
        cout << "No input! Bye." << endl;
    }
    return 0;
}
