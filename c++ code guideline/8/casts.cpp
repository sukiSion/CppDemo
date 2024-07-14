#include<iostream>


int main(int argc, char const *argv[])
{
    double d = 2;
    auto p = (long*)&d;
    auto q = (long long*)&d;
    // p和q解引用后会输出意外的结果
    std::cout << d << " " << *p << " " << *q << '\n';
    return 0;
}
