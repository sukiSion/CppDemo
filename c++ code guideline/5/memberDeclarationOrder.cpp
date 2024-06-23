#include<iostream>

class Foo{
    int m1;
    int m2;
    public:
    // 由于m1声明在m2前面，所以m1先被初始化为++x，即x+1之后的值，然后初始化m2，而此时的x时原本x+1之后的值
    Foo(int x): m2{x} , m1{++x}{
        std::cout << "m1: " << m1 << std::endl;
        std::cout << "m2: " << m2 << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    std::cout << '\n';
    Foo foo(1);
    std::cout << '\n';
    return 0;
}
