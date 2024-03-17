#include "brass.h"
#include<iostream>

using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f,  precis p);

Brass::Brass(const std::string & s , long an  , double bla){
    fullName = s;
    accNum = an;
    balance = bla;
}

void Brass::Deposit(double amt){
    if(amt < 0){
        cout << "Negative deposi not allowed; deposit is canceled." << endl;
    }else{
        balance += amt;
    }
}

void Brass::Withdraw(double amt){
    format initialState = setFormat();
    precis prec = cout.precision(2);

    if(amt < 0){
        cout << "WithDrawal amount must be positive; withdrawal canceled." << endl;
    }else if(amt <= balance){
        balance -= amt;
    }else{
        cout << "WithDrawal amount $" << amt << " exceeds your banlance." << endl << "Withdrawal canceled." << endl;
    }
    restore(initialState , prec);
}

void Brass::ViewAcct() const{
    format initialState = setFormat();
    precis prec = cout.precision(2);
    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << accNum << endl;
    cout << "Banlance: $" << balance << endl; 
    restore(initialState , prec);
}



BrassPlus::BrassPlus(const std::string & s , long an , double bal , double ml , double r)
: Brass(s , an , bal){
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

BrassPlus::BrassPlus(const Brass & ba , double ml, double r): Brass(ba){
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

void BrassPlus::ViewAcct() const{
    format initialState = setFormat();
    precis prec = cout.precision(2);
    Brass::ViewAcct();
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bankL $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan rate: " << 100 * rate << "%"  << endl;
    restore(initialState , prec);  
}


void BrassPlus::Withdraw(double amt){
    format initialState = setFormat();
    precis prec = cout.precision(2);
    double balance = Balance();
    if(amt <= balance){
        Brass::Withdraw(amt);
    }else if (amt <= balance + maxLoan - owesBank){
        double advance = amt - balance;
        owesBank += advance * (1 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    }else{
        cout << "Credit limit exceeded. Transacation canceled." << endl;
    }
    
    restore(initialState , prec);
}

format setFormat(){
    return cout.setf(std::ios_base::fixed , std::ios_base::floatfield);
}

void restore(format f , precis p){
    cout.setf(f , std::ios_base::floatfield);
    cout.precision(p);
}

