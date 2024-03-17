#include "classic.h"
#include<iostream>
#include<cstring>
using std::endl;
using std::cout;

Cd::Cd(const char * s1 , const char * s2 , int n , double x){ 
    strcpy(performers , s1);
    strcpy(label , s2 );
    selections = n;
    playtime = x;
}

Cd::Cd(){
    strcpy(performers , "none");
    strcpy(label , "null");
    selections = 0;
    playtime = 0.0;
}

void Cd::Report() const{
    cout << "performers: " << performers << endl;
    cout << "label: " << label << endl;
    cout << "selections: " << selections << endl;
    cout << "playtime:" << playtime << endl;
}

Classic::Classic(const char * w1 , const char * w2 , const char * s1 , const char * s2 , int n , double x): Cd(s1 , s2 , n , x){
    strcpy(work1 , w1);
    strcpy(work2 , w2);
}

Classic::Classic():Cd() {
    strcpy(work1 , "null");
    strcpy(work2 , "null");
}

void Classic::Report() const{
    cout << "work1: " << work1 << endl;
    cout << "work2: " << work2 << endl;
    Cd::Report(); 
}
