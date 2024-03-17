#include "port.h"
#include <cstring>

Port::Port(const char * br , const char *st , int b){
    brand = new char[strlen(br) + 1];
    strcpy(brand , br);
    strncpy(style , st , 19);
    style[19] = '\0';
    bottles = b;
}

Port::Port(const Port & p){
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand , p.brand);
    strncpy(style , p.style , 19);
    style[19] = '\0';
    bottles = p.bottles;
}

Port & Port::operator=(const Port & p){
    if(&p == this){
        return *this;
    }
    delete [] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand , p.brand);
    strncpy(style , p.style , 19);
    style[19] = '\0';
    bottles = p.bottles;
    return *this;
}

Port & Port::operator+=(int b){
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b){
    bottles -= b;
    return *this;
}

void Port::Show() const{
    cout << "brand: " << brand << endl;
    cout << "style: " << style << endl;
    cout << "bottles: " << bottles << endl;
}

ostream & operator<<( ostream &  os , const Port & p){
    os << p.brand << ", " << p.style << ", " << p.bottles << endl;
    return os;
}

VintagePort::VintagePort(const char * br , int b , const char *nn , int y)
:Port(br , "none" , b){
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname , nn);
    year = y;   
}

VintagePort::VintagePort(const VintagePort & vp): Port(vp){
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname , vp.nickname);
    year = vp.year;  
}

VintagePort::VintagePort(): Port(){
    const char * none = "none";
    nickname = new char[strlen(none) + 1];
    strcpy(nickname , none);
    year = 0;
}

VintagePort & VintagePort::operator=(const VintagePort & vp){
    if(&vp == this){
        return *this;
    }
    Port::operator=(vp);
    delete [] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname , vp.nickname);
    year = vp.year; 
    return *this;
}

void VintagePort::Show() const{
    Port::Show();
    cout << "Nickname: " << nickname  << endl;
    cout << "Year: " << year << endl;
}

ostream & operator<<(ostream &  os , const VintagePort & vp){
    os << static_cast<const Port &>(vp);
    os << vp.nickname << ", " << vp.year << endl;
    return os;
}