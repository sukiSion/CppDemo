#include<iostream>
#include<string>

struct Base{
    virtual std::string getName() const{
        return "Base";
    }
};

struct Derived: Base{
    virtual std::string getName() const{
        return "Derived";
    }
};

int main(int argc, char const *argv[])
{

    std::cout << '\n';
    Base b;
    std::cout << "b.getName(): " << b.getName() << '\n';

    Derived d;
    std::cout << "d.getName(): " << d.getName() << '\n';

    // 切片
    Base b1 = d;
    std::cout << "b1.getName(): " << b1.getName() << '\n';

    // Base为多态类，可以使用引用或者指针使得对象获得多态行为
    Base& b2 = d;
    std::cout << "b2.getName(): " << b2.getName() << '\n';

    Base *b3 = new Derived;
    std::cout << "b3->getName(): " << b3->getName() << '\n';
    return 0;
}
