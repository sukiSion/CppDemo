#include "brass.h"
#include<iostream>
int main(int argc, char const *argv[])
{
    using std::cout;
    using std::endl;
    Brass Piggy("Porcelot Pigg" , 381299 , 4000.00);
    BrassPlus Hoggy("Horatio Hogg" , 382288 , 3000.00);
    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;
    cout << "Depositing $1000 into the Hogg Account: " << endl;
    Hoggy.Deposit(1000);
    cout << "New balance: $" << Hoggy.Balance() << endl;
    cout << "WithDrawing $4200 from the Pigg Account: " << endl;
    Piggy.Withdraw(4200); 
    cout << "Pigg account balance: $" << Piggy.Balance() << endl;
    cout << "WithDrawinf $4200 from the Hogg Account: " << endl;
    Hoggy.Withdraw(4200);
    Hoggy.ViewAcct();
    return 0;
}
