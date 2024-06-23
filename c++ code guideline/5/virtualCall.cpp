#include<iostream>

struct Base{
    Base(){
        f();
    }
    virtual void f(){
        std::cout << "Base Called" << std::endl;
    }
};

struct Derived: Base{
    virtual void f() override{
        std::cout << "Derived called" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    std::cout << '\n';
    // 由于Derived构造时会构造基类，而基类构造调用自身f()
    // 而Derived本身默认构造函数不进行任何处理，所以最后导致只有虚基类的f()被调用
    Derived d;
    std::cout << '\n';
    return 0;
}
