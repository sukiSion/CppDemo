#include<iostream>
#include<string>

// 主模板
template<typename T>
std::string getTypeName(T){
    return "unknown type";
}

// 函数模板仅支持全特化
template<>
std::string getTypeName<int>(int){
    return "int";
}

// 函数重载
std::string getTypeName(double){
    return "double";
}

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    std::cout << "getTypeName(true): " << getTypeName(true) << '\n';
    std::cout << "getTypeName(4711): " << getTypeName(4711) << '\n';
    std::cout << "getTypeName(3.14): " << getTypeName(3.14) << '\n';


    std::cout << '\n';

    return 0;
}
