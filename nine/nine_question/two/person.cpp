#include<cstring>
#include<iostream>
#include<string>
#include "person.h"
using std::string;
using std::cout;
using std::endl;

Person::Person(const string & ln , const char * fn){
    lname = ln;
    strncpy(fname , fn , LIMIT - 1);
    fname[LIMIT - 1] = '\0';
}

void Person::Show() const{
    cout << "name: " <<  fname << ", " << lname << endl;
}

void Person::FormalShow() const{
    cout << "name: " <<  lname << ", " << fname << endl;
}