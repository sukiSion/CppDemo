#include<iostream>
#include<cstring>
#include<cmath>
#include "account.h"

BankAccount::BankAccount(const char * client, const char * num, double bal){
    strncpy(name , client , 39);
    name[39] = '\0';
    strncpy(acctnum , num , 24);
    name[24] = '\0';
    balance = bal; 
}

void BankAccount::show() const{
    using std::cout;
    using std::endl;
    cout << "name: " << name << ", acctnum: " << acctnum << ", banlance: " << balance << endl;
}

void BankAccount::deposit(double cash){
    if(cash >= 0){
        balance += cash;
    }
}

void BankAccount::withdraw(double cash){
    if(cash < 0) return;
    balance -= std::min(cash , balance);
}

