#include<iostream>
#include<string>

struct Base{
    void shadow(std::string){
        std::cout << "Base::shadow" << '\n';
    }
};

struct Derived: Base{
    using Base::shadow; // 由于在类层次中使用重载同名函数会覆盖，故需要使用using为派生类及其基类创建重载集
    void shadow(int){
        std::cout << "Derived::shadow" << '\n';
    }
};

int main(int argc, char const *argv[])
{
    std::cout << '\n';
    Derived derived;
    derived.shadow(std::string{});
    derived.shadow(int{});
    std::cout << '\n';
    return 0;
}
