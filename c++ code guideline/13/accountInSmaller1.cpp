#include<iostream>
// 对类重载<
// 是通用解决方案，在编译期配置，扩展了类，不具有可变性
class Account{
    public:
    Account() = default;
    Account(double b): balance(b){}
    double getBalance() const{
        return balance;
    }
    friend bool operator < (Account const& fir , Account const& sec){
        return fir.getBalance() < sec.getBalance();
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
