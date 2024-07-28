#include<memory>
struct MyType{
    MyType(int , double , bool){}
};

/**
 * 典型的工厂函数
 * std::make_unique可以处理任意数量的参数
 * std::make_unique可以接收左值和右值
 * std::make_unique可以将其参数原封不动地转发给底层构造函数
 */
int main(int argc, char const *argv[])
{
    int lvalue{2020};
    std::unique_ptr<int> uniqZero = std::make_unique<int>();
    auto uniqEleven = std::make_unique<int>(2011);
    auto uniqTwenty = std::make_unique<int>(lvalue);
    auto uniqType = std::make_unique<MyType>(lvalue , 3.14 , true);
    return 0;
}
