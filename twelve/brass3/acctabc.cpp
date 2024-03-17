#include "acctabc.h"
using std::cout;
using std::endl;


AcctABC::Formatting AcctABC::SetFormat() const{
    Formatting f;
    f.flag = cout.setf(std::ios_base::fixed , std::ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::Restore(Formatting & f) const{
    cout.setf(std::ios_base::fixed , f.flag);
    cout.precision(f.pr);
}

AcctABC::AcctABC(const std::string & s , long an , double bal){
    fullName = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt){
    if(amt < 0){
        cout << "Negative deposit not allowed; deposit is canceled." << endl;
    }else{
        balance += amt;
    }
}

void AcctABC::Withdraw(double amt){
    balance -= amt;
}

void Brass::ViewAcct() const{
    Formatting f = SetFormat();
    cout << "Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Banlance: $" << Balance() << endl; 
    Restore(f);
}

void Brass::Withdraw(double amt){
    Formatting f = SetFormat();

    if(amt < 0){
        cout << "Withdrawal amount must be positive; withdrawal canceled." << endl;
    }else if(amt <= Balance()){
        AcctABC::Withdraw(amt);
    }else{
        cout << "Withdrawal amount of $" << amt << " exceeds your banlance." << endl << "Withdrawal canceled." << endl;
    }
    Restore(f);
}

BrassPlus::BrassPlus(const std::string & s , long an , double bal , double ml , double r)
: AcctABC(s , an , bal){
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

BrassPlus::BrassPlus(const AcctABC & ba , double ml, double r): AcctABC(ba){
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

void BrassPlus::ViewAcct() const{
    Formatting f = SetFormat();
    cout << "Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Banlance: $" << Balance() << endl; 
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bankL $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan rate: " << 100 * rate << "%"  << endl;
    Restore(f);
}

void BrassPlus::Withdraw(double amt){
    Formatting f = SetFormat();
    double bal = Balance();
    if(amt <= bal){
        AcctABC::Withdraw(amt);
    }else if(amt <= bal + maxLoan - owesBank){
        double advance = amt - bal;
        owesBank += advance * (1 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }else{
        cout << "Credit limit exceeded. Transacation canceled." << endl;
    }
    Restore(f);
}