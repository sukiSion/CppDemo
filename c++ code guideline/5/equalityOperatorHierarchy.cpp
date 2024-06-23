#include<iostream>
#include<string>

struct Base{
    std::string name;
    int number;
    virtual bool operator==(const Base & a) const{
        return name == a.name && number == a.number;
    }
};

struct Derived: Base{
    char character;
    virtual bool operator==(const Derived& a) const{
        return name == a.name && number == a.number && character == a.character;
    }
};

int main(int argc, char const *argv[])
{
    Base b;
    Base& base = b;
    Derived d;
    Derived& derived = d;

    // 使用了Base的相等运算符，只比较了name和number
    base = derived;

    // 错误的，因为没有定义Derived与Base进行比较的运算符
    // derived == base;

    Derived derived2;
    derived == derived2;

    Base& base2 = derived2;
    // 使用了Base的运算符：
    // 由于两个运算符签名不同：一个需要Base实例一个需要derived实例所以Derived版本没有覆盖Base版本
    // base2虽然引用的是derived2，但由于相等运算符没有被覆盖，所以调用了Base的运算符
    base2 == derived2;
    return 0;
}
