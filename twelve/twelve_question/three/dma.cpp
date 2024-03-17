#include "dma.h"
#include<cstring>
#include<iostream>
using std::cout;
using std::endl;

abcDMA::abcDMA(const char * l , int r){
    int len = strlen(l);
    label = new char[len + 1];
    strncpy(label , l , len);
    label[len] = '\0';
    rating = r;
}

abcDMA::abcDMA(const abcDMA & rs){
    int len = strlen(rs.label);
    label = new char[len + 1];
    strncpy(label , rs.label , len);
    label[len] = '\0';
    rating = rs.rating;
}

abcDMA & abcDMA::operator=(const abcDMA & rs){
    if(this == &rs){
        return *this;
    }
    delete [] label;
    int len = strlen(rs.label);
    label = new char[len + 1];
    strncpy(label , rs.label , len);
    label[len] = '\0';
    rating = rs.rating;
    return *this;
}

abcDMA::~abcDMA(){
    delete [] label;
}

void abcDMA::View() const{
    cout << "Label: " <<  label << endl;
    cout << "Rating: " << rating << endl;
}

baseDMA::baseDMA(const char * l , int r):abcDMA(l , r){

}

baseDMA::baseDMA(const baseDMA & rs): abcDMA(rs){

}

void baseDMA::View() const{
    abcDMA::View();
}


lacksDMA::lacksDMA(const char * s , const char * l , int r): abcDMA(l , r){
    strncpy(color , s , COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char * s , const abcDMA & rs): abcDMA(rs){
    strncpy(color , s , COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}


void lacksDMA::View() const{
    abcDMA::View();
    cout << "Color: " << color << endl;
}

hasDMA::hasDMA(const char * s , const char * l , int r): abcDMA(l , r){
    int len = strlen(s);
    style = new char[len + 1];
    strncpy(style , s , len);
    style[len] = '\0';
}

hasDMA::hasDMA(const char * s , const abcDMA & rs):abcDMA(rs){
    int len = strlen(s);
    style = new char[len + 1];
    strncpy(style , s , len);
    style[len] = '\0';
}

hasDMA::hasDMA(const hasDMA & hs): abcDMA(hs){
    int len = strlen(hs.style);
    style = new char[len + 1];
    strncpy(style , hs.style , len);
    style[len] = '\0';
}

hasDMA & hasDMA::operator=(const hasDMA & hs){
    if(this == &hs){
        return *this;
    }
    abcDMA::operator=(hs);
    delete [] style;
    int len = strlen(hs.style);
    style = new char[len + 1];
    strncpy(style , hs.style , len);
    style[len] = '\0';
    return *this;
}

hasDMA::~hasDMA(){
    delete [] style;
}

void hasDMA::View() const{
    abcDMA::View();
    cout << "Style: " << style << endl;
}