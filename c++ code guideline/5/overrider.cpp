#include<iostream>

class Base{
    public:
    // 由于成员函数是虚函数，所以延迟绑定
    // 但是默认参数和数据成员是静态绑定的，所以即使基类指针或者引用指向派生类对象
    // 调用时若基类有默认参数则会优先使用基类的默认参数
    virtual int multiply(int value , int factor = 2) = 0;
};

class Derived: public Base{
    public:
    int multiply(int value , int factor = 10) override{
        return factor * value;
    }
};

int main(int argc, char const *argv[])
{
    std::cout << '\n';
    Derived d;
    Base& b = d;
    // 输出20，使用了基类的默认参数，即使是虚函数也没有延迟绑定默认参数
    std::cout << "b.multiply(10): " << b.multiply(10) << '\n';
    // 输出100
    std::cout << "d.multiply(10): " << d.multiply(10) << '\n';
    std::cout << '\n';
    return 0;
}
