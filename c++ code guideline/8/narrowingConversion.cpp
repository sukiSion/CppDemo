#include<iostream>

int main(int argc, char const *argv[])
{
    char c1(999);
    // 由于{}检测窄化转换，因此可以发现程序是劣构的
    // 至少会诊断出一个警告，但大多数会把窄化转换当作错误处理
    // char c1{999};
    char c2 = 999;
    // 同上
    // char c2 = {999};
    std::cout << "c1: " << c1 << '\n';
    std::cout << "c2: " << c2 << '\n';
    int i1(3.14);
    // 同上
    // int i1{3.14};
    int i2 = 3.14;
    // 同上
    // int i2 = {3.14};
    std::cout << "i1: " << i1 << '\n';
    std::cout << "i2: " << i2 << '\n';
    return 0;
}
