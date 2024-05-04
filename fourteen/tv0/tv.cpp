#include "tv.h"
#include<iostream>

bool Tv::volup(){
    if(volume < MaxVal){
        volume ++;
        return true;
    }else{
        return false;
    }
}

bool Tv::voldown(){
    if(volume > MinVal){
        volume--;
        return true;
    }else{
        return false;
    }
}

void Tv::chanup(){
    if(channel < maxChannel){
        channel++;
    }else{
        channel = maxChannel;
    }
}

void Tv::chandown(){
    if(channel > 1){
        channel--;
    }else{
        channel = 1;
    }
}

void Tv::settings() const{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off? "Off" : "On") << endl;
    if(ison()){
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = " << (mode == Antenna ? "antenna" : "cable") << endl;
        cout << "Input = " << (input == TV ? "TV" : "DVD") << endl;
    }
}