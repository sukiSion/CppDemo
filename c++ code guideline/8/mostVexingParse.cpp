#include<iostream>

struct MyInt{
    MyInt(int arg = 0): i(arg){}
    int i;
};

int main(int argc, char const *argv[])
{
    MyInt myInt(2011);
    // 这里既可以表示构造函数的调用也可以表示为对函数的声明：函数名为myInt2，返回值为MyInt从而产生歧义
    // MyInt myInt2();
    // 使用{}初始化可以解决这个问题
    MyInt myInt2{};

    std::cout << myInt.i;
    std::cout << myInt2.i;
    return 0;
}
