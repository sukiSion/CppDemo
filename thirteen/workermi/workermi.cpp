#include "workermi.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
Worker::~Worker(){}

void Worker::Data() const{
    cout << "Name: " << fullname << endl;
    cout << "Employee ID: " << id << endl;
}

void Worker::Get(){
    getline(cin , fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while(cin.get() != '\n');
}

void Waiter::Data() const{
    cout << "Panache rating: " << panache << endl;
}

void Waiter::Get(){
    cout << "Enter waiter's panache rating: ";
    cin >> panache;
    while(cin.get() != '\n');
}

void Waiter::Show() const{
    cout << "Category: waiter" << endl;
    Worker::Data();
    Data();
}

void Waiter::Set(){
    cout << "Enter waiter's name: ";
    Worker::Get();
    Get();
}

const char * Singer::pv[] = {
    "other",
    "alto",
    "contralto",
    "soprano",
    "bass",
    "baritone",
    "tenor"
};

void Singer::Data() const{
    cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Get(){
    cout << "Enter number for singer's vocal range:" << endl;
    int i;
    for(i = 0 ; i < Vtypes ; i++){
        cout << "i" << ": " << pv[i] << " ";
        if(i % 4 == 3){
            cout << endl;
        }
    }
    if(i % 4 != 0){
        cout << endl;
    }
    while(cin >> voice && (voice < 0 || voice >= Vtypes)){
        cout << "Please enter a value >= 0 and < " << Vtypes << endl;
    }
    while(cin.get() != '\n');
}

void Singer::Show() const{
    cout << "Category: singer" << endl;
    Worker::Data();
    Data();
}

void Singer::Set(){
     cout << "Enter singer's name: ";
     Worker::Get();
     Get();
}

void SingingWaiter::Get(){
    Singer::Get();
    Waiter::Get();
}

void SingingWaiter::Data() const{
    Singer::Data();
    Waiter::Data();
}

void SingingWaiter::Set(){
    cout << "Enter singing waiter's name: ";
    Worker::Get();
    Get();
}

void SingingWaiter::Show() const{
    cout << "Category: singing waiter" << endl;
    Worker::Data();
    Data();
}
