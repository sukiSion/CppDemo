#include "classic.h"
#include<cstring>
#include<iostream>
using std::cout;
using std::endl;

static const char * null = "null";
static const char * none = "none";

Cd::Cd(const char * s1 ,  const char * s2 , int n , double x){
    performers = new char[strlen(s1)+ 1];
    strcpy(performers , s1);
    label = new char[strlen(s2) + 1];
    strcpy(label , s2);
    selections = n;
    playtime = x;
}

Cd::Cd(){
    performers = new char[strlen(none) + 1];
    strcpy(performers , none);
    label = new char[strlen(null) + 1];
    strcpy(label , null);
    selections = 0;
    playtime = 0.0;
}

Cd::Cd(const Cd & d){
    performers = new char[strlen(d.performers)+ 1];
    strcpy(performers , d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label , d.label);
    selections = d.selections;
    playtime = d.playtime;
}

void Cd::Report() const{
    cout << "performers: " << performers << endl;
    cout << "label: " << label << endl;
    cout << "selections: " << selections << endl;
    cout << "playtime:" << playtime << endl;
}

Cd & Cd::operator=(const Cd & d){
    if(&d == this){
        return *this;
    }
    delete [] performers;
    delete [] label;
    performers = new char[strlen(d.performers)+ 1];
    strcpy(performers , d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label , d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

Cd::~Cd(){
    delete [] performers;
    delete [] label;
}

Classic::Classic(const char * w1 , const char * w2 ,  const char * s1 ,  const char * s2 , int n , double x)
:Cd(s1 , s2 , n , x){
    work1 = new char[strlen(w1) + 1];
    strcpy(work1 , w1);
    work2 = new char[strlen(w2) + 1];
    strcpy(work2 , w2);
}

Classic::Classic():Cd(){
    work1 = new char[strlen(null)+ 1];
    strcpy(work1 , null);
    work2 = new char[strlen(null) + 1];
    strcpy(work2 , null);
}

Classic::Classic(const Classic & c): Cd(c){
    work1 = new char[strlen(c.work1)+ 1];
    strcpy(work1 , c.work1);
    work2 = new char[strlen(c.work2) + 1];
    strcpy(work2 , c.work2);
}

Classic::~Classic(){
    delete [] work1;
    delete [] work2;
}

void Classic::Report() const{
    cout << "work1: " << work1 << endl;
    cout << "work2: " << work2 << endl;
    Cd::Report(); 
}

Classic & Classic::operator=(const Classic & c){
    if(&c == this){
        return *this;
    }
    Cd::operator=(c);
    delete [] work1;
    delete [] work2;
    work1 = new char[strlen(c.work1)+ 1];
    strcpy(work1 , c.work1);
    work2 = new char[strlen(c.work2) + 1];
    strcpy(work2 , c.work2);
    return *this;
}