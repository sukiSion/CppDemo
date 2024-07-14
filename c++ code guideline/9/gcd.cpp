#include<iostream>

// 声明为constexpr不代表必须在编译期运行，也可能在运行期运行
constexpr int gcd(int a , int b){
    while(b != 0){
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    // 使用constexpr变量请求结果，所以是常量表达式
    // 在常量表法式中使用constexpr函数必须在编译期执行
    constexpr auto res1 = gcd(121 , 11);

    // 没有使用constexpr，所以不是常量表达式
    auto val = 121;
    // 没有使用constexpr，所以不是常量表达式
    // 此时constexpr函数在运行期执行
    auto res2 = gcd(121 , 11);
    std::cout << '\n';

    return 0;
}

