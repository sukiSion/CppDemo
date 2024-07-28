#include<iostream>

template<int N>
struct Factorial{
    static int const value = N * Factorial<N - 1>::value;
};

// 该显式实例化是必须的，作为递归的结束条件
template<>
struct Factorial<1>{
    static int const value = 1;
};

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    std::cout << "Factorial<5>::value: " << Factorial<5>::value << '\n';
    std::cout << "Factorial<10>::value: " << Factorial<10>::value << '\n';

    std::cout << '\n';

    return 0;
}
