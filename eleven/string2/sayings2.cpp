#include<iostream>
#include "string2.h"
#include<cstdlib>
#include<ctime>
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
        String * shortest = &sayings[0];
        String * first = &sayings[0];
        for(i = 0 ; i < total ; i++){
            if(sayings[i].length() < (*shortest).length()){
                shortest = &sayings[i];
            }
            if(sayings[i] < *first){
                first = &sayings[i];
            }
        }
        cout << "Shortest saying: " << endl;
        cout << *shortest << endl;
        cout << "First alphabetically: " << endl;
        cout << *first << endl;
        srand(time(0));
        int choice = rand() % total;
        String * favorite = new String(sayings[choice]);
        cout << "My favorite saying: " << endl;
        cout << *favorite << endl;
        delete favorite;
    }else{
        cout << "No input! Bye." << endl;
    }
    cout << "Bye." << endl;
    return 0;
}
