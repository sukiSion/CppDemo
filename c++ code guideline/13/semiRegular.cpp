#include<iostream>
#include<type_traits>

int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha << '\n';

    // 该类型是否可以被默认构造
    std::cout << "std::is_default_constructible<int&>::value: " << std::is_default_constructible<int&>::value << '\n';
    // 该类型是否可以被拷贝构造
    std::cout << "std::is_copy_constructible<int&>::value: " << std::is_copy_constructible<int&>::value << '\n';
    // 该类型是否可以拷贝赋值
    std::cout << "std::is_copy_assignable<int&>::value: " << std::is_copy_assignable<int&>::value << '\n';
    // 该类型是否可以被移动构造
    std::cout << "std::is_move_constructible<int&>::value: " << std::is_move_constructible<int&>::value << '\n';
    // 该类型是否可以移动赋值
    std::cout << "std::is_move_assignable<int&>::value: " << std::is_move_assignable<int&>::value << '\n';
    // 该类型是否可以被析构
    std::cout << "std::is_destructible<int&>::value: " << std::is_destructible<int&>::value << '\n';
    // 该类型是否可以交换
    std::cout << "std::is_swappable<int&>::value: " << std::is_swappable<int&>::value << '\n';

    std::cout << '\n';
    return 0;
}
