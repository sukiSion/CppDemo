#include<iostream>
#include<cstring>
#include "golf.h"

void setgolf(golf & g , const char * name , int hc){
    strcpy(g.fullname , name);
    g.handicap = hc;
}
int setgolf(golf & g){
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "Enter name: ";
    cin.get(g.fullname , Len);
    if(!cin || strlen(g.fullname) == 0){
        return 0;
    }
    while (cin.get() != '\n');
    cout << "Enter handicap: ";
    (cin >> g.handicap).get();
    return 1;
}
void handicap(golf & g , int hc){
    g.handicap = hc;
}
void showgolf(const golf & g){
    using std::cout;
    using std::endl;
    cout << "name: " << g.fullname << ", handicap: " << g.handicap << endl;
}