#include<iostream>

struct Base{
    public:
    void func(int i){
        std::cout << "Base::func(int)\n";
    }
    void func(double d){
        std::cout << "Base::func(double)\n";
    }
};

struct Derived: public Base{
    public:
    void func(int i){
        std::cout << "Derived::func(int)\n";
    }
    // 需要导入基类整个重载集，暴露出func(double)
    // 若没有这条语句，当Derived调用func(double)时会发生double到int的窄化转化，从而调用func(int)
    using Base::func;
};

int main(int argc, char const *argv[])
{
    std::cout << '\n';
    Derived der;
    der.func(2011);
    der.func(2020.5);
    std::cout << '\n';
    return 0;
}
