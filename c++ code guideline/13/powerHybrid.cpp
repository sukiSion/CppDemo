#include<iostream>

template<int n>
int power(int m){
    return m * power<n - 1>(m);
}

template<>
int power<0>(int m){
    return 1;
}

int main(int argc, char const *argv[])
{
    std::cout << '\n';
    // 10是编译期参数，2是运行期参数
    std::cout << "power<10>(2): " << power<10>(2) << '\n';
    std::cout << '\n';
    // 实例化模板，编译期调用
    auto power2 = power<2>;
    // 由于函数参数是运行期参数，所以可以使用for循环（运行期调用）
    for(int i = 0 ; i < 10 ; ++i){
        std::cout << "power2(" << i << ") = " << power2(i) << '\n';
    }
    std::cout << '\n';
    return 0;
}
