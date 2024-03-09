#include "stringbad.h"
#include<cstring>
using std::cout;
using std::endl;

int StringBad::num_strings = 0;

StringBad::StringBad(){
    len = 3;
    str = new char[len + 1];
    strcpy(str , "C++");
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object created" << endl; 
}

StringBad::StringBad(const char * s){
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str , s);
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object created" << endl; 
}

StringBad::~StringBad(){
    cout << "\"" << str << "\" object deleted, " << --num_strings << " left" << endl;
    delete [] str;
}

std::ostream & operator<<(std::ostream & os , const StringBad & st){
    os << st.str;
    return os;
}