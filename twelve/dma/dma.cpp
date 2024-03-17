#include "dma.h"
#include<cstring>

baseDMA::baseDMA(const char * l , int r){
    int len = strlen(l);
    label = new char[len + 1];
    strncpy(label , l , len);
    label[len] = '\0';
    rating = r;
}

baseDMA::baseDMA(const baseDMA & rs){
    int len = strlen(rs.label);
    label = new char[len + 1];
    strncpy(label , rs.label , len);
    label[len] = '\0';
    rating = rs.rating;
}

baseDMA & baseDMA::operator=(const baseDMA & rs){
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

 std::ostream & operator<<( std::ostream & os , const baseDMA & rs){
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}

baseDMA::~baseDMA(){
    delete [] label;
}

lacksDMA::lacksDMA(const char * s , const char * l , int r): baseDMA(l , r){
    strncpy(color , s , COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char * s , const baseDMA & rs): baseDMA(rs){
    strncpy(color , s , COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os , const lacksDMA & ls){
    os << static_cast<const baseDMA & > (ls);
    os << "Color: " << ls.color << std::endl;
    return os;
}

hasDMA::hasDMA(const char * s , const char * l , int r): baseDMA(l , r){
    int len = strlen(s);
    style = new char[len + 1];
    strncpy(style , s , len);
    style[len] = '\0';
}

hasDMA::hasDMA(const char * s , const baseDMA & rs):baseDMA(rs){
    int len = strlen(s);
    style = new char[len + 1];
    strncpy(style , s , len);
    style[len] = '\0';
}

hasDMA::hasDMA(const hasDMA & hs): baseDMA(hs){
    int len = strlen(hs.style);
    style = new char[len + 1];
    strncpy(style , hs.style , len);
    style[len] = '\0';
}

hasDMA & hasDMA::operator=(const hasDMA & hs){
    if(this == &hs){
        return *this;
    }
    baseDMA::operator=(hs);
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

std::ostream & operator<<(std::ostream & os , const hasDMA & hs){
    os << static_cast<const baseDMA & > (hs);
    os << "Style: " << hs.style << std::endl;
    return os;
}