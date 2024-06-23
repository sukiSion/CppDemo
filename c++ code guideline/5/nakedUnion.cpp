#include<iostream>

union Value{
    int i;
    double d;
};

int main(int argc, char const *argv[])
{
    std::cout << '\n';
    Value v;
    // 此时该联合体持有一个double
    v.d = 987.654;
    std::cout << "v.d: " << v.d << '\n';
    // 未定义行为：将double读成一个int
    std::cout << "v.i: " << v.i << '\n';
    std::cout << '\n';

    // 此时该联合体持有一个int
    v.i = 123;
    std::cout << "v.i: " << v.i << '\n';
    // 未定义行为：将int读成一个double
    std::cout << "v.d: " << v.d << '\n';
    std::cout << '\n';
    return 0;
}
