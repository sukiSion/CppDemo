#include "cow.h"
#include<iostream>
#include<cstring>

Cow::Cow(){
    weight = 0;
    hobby = new char[1];
    hobby[0] = '\0';
    name[0] = '\0';
}

Cow::Cow(const char * nm , const char * ho , double wt){
    strcpy(name , nm);
    hobby = new char[strlen(ho) + 1];
    strcpy(hobby , ho);
    weight = wt;
}

Cow::Cow(const Cow & c){
    weight = c.weight;
    strcpy(name , c.name);
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby , c.hobby);  
}

Cow::~Cow(){
    delete [] hobby; 
}

Cow & Cow::operator=(const Cow & c){
    if(this == &c){
        return *this;
    }
    delete [] hobby;  
    strcpy(name , c.name);
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby , c.hobby);
    weight = c.weight;
    return *this;
}

void Cow::ShowCow() const{
    std::cout << "name: " << name << ", hobby: " << hobby << ", weight: " << weight << std::endl;
}