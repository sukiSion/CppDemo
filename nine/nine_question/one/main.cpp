#include<iostream>
#include "account.h"

int main(int argc, char const *argv[])
{
    BankAccount sionAccount("Sion" , "842143912");
    sionAccount.show();
    sionAccount.deposit(6000.3);
    sionAccount.show();
    sionAccount.withdraw(6000);
    sionAccount.show();
    return 0;
}
