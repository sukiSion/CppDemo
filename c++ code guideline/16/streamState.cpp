#include<iostream>
#include<ios>

int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha << '\n';

    std::cout << "In failbit-state: " << std::cin.fail() << '\n';

    std::cout << '\n';

    int myInt;
    while(std::cin >> myInt){
        std::cout << "Output: " << myInt << '\n';
        std::cout << "In failbit-state: " << std::cin.fail() << '\n';
        std::cout << '\n';
    }

    // 错误标志位被置位
    std::cout << "In failbit-state: " << std::cin.fail() << '\n';
    // 清空错误标志位才能继续进行读取
    std::cin.clear();
    std::cout << "In failbit-state: " << std::cin.fail() << '\n';

    std::cout << '\n';
    return 0;
}
