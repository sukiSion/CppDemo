#include<iostream>
extern double warming;
void update(double dt);
void local();

using std::cout;
using std::endl;
void update(double dt){
    extern double warming;
    warming += dt;
    cout << "Updating global warming to " << warming << " degress." << endl;
}

void local(){
    double warming = 0.8;
    cout << "Local warming is " << warming << " degress." << endl;
    cout << "Bue global warming = " << ::warming << " degress." << endl;
}