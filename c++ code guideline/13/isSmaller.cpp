#include<iostream>
// 由于Account类没有重载<运算符所以无法进行比较
class Account{
    public:
    Account() = default;
    Account(double b): balance(b){}
    double getBalance() const{
        return balance;
    }
    private:
    double balance{0.0};
};

template<typename T>
bool isSmaller(T fir , T sec){
    return fir < sec;
}

int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha << '\n';

    double firDoub{};
    double secDoub{2014.0};

    std::cout << "isSmaller(firDoub , secDoub): " << isSmaller(firDoub , secDoub) << '\n';
    Account firAcc{};
    Account secAcc{2014.0};

    std::cout << "isSmaller(firAcc , secAcc): " << isSmaller(firAcc , secAcc) << '\n';

    std::cout << '\n';
    return 0;
}
