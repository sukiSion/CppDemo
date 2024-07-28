#include<iostream>
#include<functional>
#include<string>

// 扩展比较函数
// 是通用解决方案，在运行期配置，扩展了函数，具有可变性
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

// 通过传入额外的类型参数Pred来扩展泛型
// Pred可以容纳一个二元谓词，通过传入对应类型的二元谓词函数即可进行特化比较
// std::less<T>作为预定义的函数对象作为默认顺序
template<typename T , typename Pred = std::less<T>>
bool isSmaller(T fir , T sec , Pred pred = Pred()){
    return pred(fir , sec);
}


int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha << '\n';

    double firDoub{};
    double secDoub{2014.0};

    std::cout << "isSmaller(firDoub , secDoub): " << isSmaller(firDoub , secDoub) << '\n';
    Account firAcc{};
    Account secAcc{2014.0};

    auto res = isSmaller(firAcc , secAcc , [](const Account& fir , const Account& sec){
        return fir.getBalance() < sec.getBalance();
    });
    std::cout << "isSmaller(firAcc , secAcc): " << res << '\n';
    std::cout << '\n';

    std::string firStr = "AAA";
    std::string secStr = "BB";
    std::cout << "isSmaller(firStr , secStr): " << isSmaller(firStr , secStr) << '\n';

    auto res2 = isSmaller(firStr , secStr , [](const std::string& fir , const std::string& sec){
        return fir.length() < sec.length();
    });
    std::cout << "isSmaller(firStr , secStr): " << res2 << '\n';
    return 0;
}
