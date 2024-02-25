#include<iostream>
#include "golf.h"
#include<cstring>

Golf::Golf(const char * name , int hc){
    strncpy(fullname , name , Len - 1);
    fullname[Len - 1] = '\0';
    handicap = hc;
}

int Golf::setgolf(){
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "Enter name: ";
    cin.get(fullname , Len);
    if(!cin || strlen(fullname) == 0){
        return 0;
    }
    while (cin.get() != '\n');
    cout << "Enter handicap: ";
    if(cin >> handicap){
        cin.get();
    }
    return 1;
}

void Golf::sethandicap(int hc){
    handicap = hc;
}   
    
void Golf::showgolf() const{
    using std::cout;
    using std::endl;
    cout << "name: " << fullname << ", handicap: " << handicap << endl;
}