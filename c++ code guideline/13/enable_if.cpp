#include<iostream>
#include<type_traits>

// std::is_integral决定类型参数T是否为整数
// 如果T不是整数，那么返回值是false，那么特定类型没有模板实例化
// 只有std::is_integral返回true时，std::enable_if才会有一个公开的成员类型type
template<typename T , typename std::enable_if<std::is_integral<T>::value , T>::type = 0>
T gcd(T a, T b){
    if(b == 0) {
        return a;
    }else{
        return gcd(b , a % b);
    }
}

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    std::cout << "(gcd(100 , 10)) = " << gcd(100 , 10) << '\n';
    // std::cout << "(gcd(3.5 , 4)) = " << gcd(3.5 , 4.0) << '\n';

    std::cout << '\n';
    return 0;
}
