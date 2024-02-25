// 5、创建一个银行账户的类：
// 数据成员：储户姓名、账号(字符串)、存款
// 成员函数：
// 1) 创建一个对象并将其初始化
// 2) 显示储户姓名、账号和存款
// 3) 存入参数指定的存款
// 4) 取出参数指定的存款
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

class BankAccount{
    private:
    char name[40];
    char acctnum[25];
    double balance;
    public:
    BankAccount(const char * client, const char * num, double bal = 0.0);
    void show() const;
    void deposit(double cash);
    void withdraw(double cash); 
};

#endif