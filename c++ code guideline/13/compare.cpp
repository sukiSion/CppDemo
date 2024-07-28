#include<iostream>
#include<type_traits>
#include<cstdint>

class Base{};
class Derived: public Base{};

int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha << '\n';

    // is_base_of判断一个类型是否为另一个类型的基类
    std::cout << "std::is_base_of<Base , Derived>::value: " << std::is_base_of<Base , Derived>::value << '\n';
    std::cout << "std::is_base_of<Derived , Base>::value: " << std::is_base_of<Derived , Base>::value << '\n';
    std::cout << "std::is_base_of<Derived , Derived>::value: " << std::is_base_of<Derived , Derived>::value << '\n';
    std::cout << '\n';

    // is_constructible判断一个类型是否可以隐式转换为另一个类型
    std::cout << "std::is_convertible<Base* , Derived*>::value: " << std::is_convertible<Base* , Derived*>::value << '\n';
    std::cout << "std::is_convertible<Derived* , Base*>::value: " << std::is_convertible<Derived* , Base*>::value << '\n';
    std::cout << "std::is_convertible<Derived* , Derived*>::value: " << std::is_convertible<Derived* , Derived*>::value << '\n';
    std::cout << '\n';

    // is_same判断一个类型是否和另一个类型相同
    std::cout << "std::is_same<int, int32_t>::value: " << std::is_same<int, int32_t>::value << '\n';
    std::cout << "std::is_same<int, int64_t>::value: " << std::is_same<int, int64_t>::value << '\n';
    // 64位为long long，32位为long int
    std::cout << "std::is_same<long long , int64_t>::value: " << std::is_same<long long , int64_t>::value << '\n';
    std::cout << '\n';
    return 0;
}