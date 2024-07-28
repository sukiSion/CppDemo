#include<utility>
#include<memory>

struct MyType{
    MyType(int , double , bool){}
};

/**
 * Args为模板参数包，args为函数参数包
 * std::forward<Args>(args)...意味着该表法式将会被解包
 * 直到参数包被消耗殆尽，并且会在解包后的各个部分之间放置一个逗号
 */
template<typename T , typename ...Args>
std::unique_ptr<T> createT(Args ...args){
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

int main(int argc, char const *argv[])
{
    int lvalue{2020};
    std::unique_ptr<int> uniqZero = std::make_unique<int>();
    auto uniqEleven = createT<int>(2011);
    auto uniqTwenty = createT<int>(lvalue);
    auto uniqType = createT<MyType>(lvalue , 3.14 , true);
    return 0;
}
