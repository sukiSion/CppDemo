#include<iostream>
#include<string>
#include<utility>

int main(int argc, char const *argv[])
{
    std::string hello = "hello";
    auto firstPair = std::make_pair(hello , 5); // (std::string , int)
    // 如果使用C字符串和int来创建pair将无法进行比较
    // auto secondPair = std::make_pair("hello" , 15); // (const char* , int)
    // 必须将命名空间std::string_literals来导入来使用C++字符串字面量
    using namespace std::string_literals;
    auto secondPair = std::pair("hello"s , 15); // (std::string , int)
    if(firstPair < secondPair){
        std::cout << "true\n";
    }
    return 0;
}
