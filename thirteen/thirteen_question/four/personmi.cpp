#include "personmi.h"
#include<iostream>
#include<ctime>
using std::cout;
using std::endl;
using std::cin;
using std::getline;

void Person::Data() const{
    cout << "First name: " << fname << endl;
    cout << "Last name: " << lname << endl;
}

void Person::Get() {
    cout << "Please enter your first name: ";
    getline(cin, fname);
    cout << "Please enter your last name: ";
    getline(cin, lname);
}

Person::~Person(){}

void Person::Set(){
    Person::Get();
}

void Person::Show() const{
    Person::Data();
}

void Gunslinger::Data() const{
    cout << "unslinger nicks:" << nicks << endl;
}

void Gunslinger::Get() {
    cout << "Please enter the nicks for gunslinger: ";
    cin >> nicks;
    while(cin.get() != '\n');
}

double Gunslinger::Draw() const{
    time_t now = time(0);
    return now;
}

void Gunslinger::Set(){
    cout << "Enter Gunslinger name" << endl;
    Person::Get();
    Gunslinger::Get();
}

void Gunslinger::Show() const{
    cout << "Category: Gunslinger" << endl;
    Person::Data();
    Gunslinger::Data();
}


void PokerPlayer::Data() const
{
    cout << "The cards: " << Draw() << endl;
}

void PokerPlayer::Set()
{
    cout << "Enter PokerPlayer name" << endl;
    Person::Get();
}

void PokerPlayer::Show() const{
    cout << "Category: PokerPlayer" << endl;
    Person::Data();
    Data();
}


int PokerPlayer::Draw() const{
    srand(time(0));
    return rand() % 52 + 1;
}

double BadDude::Gdraw() const
{
    return Gunslinger::Draw();
}

int BadDude::Cdraw() const
{
    return PokerPlayer::Draw();
}

void BadDude::Data() const{
    Gunslinger::Data();
    PokerPlayer::Data();
    cout << "The time for a bad guy to draw his gun is " << Gdraw() << endl;
    cout << "The next card is " << Cdraw() << endl;
}

void BadDude::Show() const{
    cout << "Category: BadDude" << endl;
    Person::Data();
    BadDude::Data();
}

void BadDude::Get(){
    Gunslinger::Get();
}

void BadDude::Set(){
    cout << "Enter BadDude name" << endl;
    Person::Get();
    BadDude::Get();
}
