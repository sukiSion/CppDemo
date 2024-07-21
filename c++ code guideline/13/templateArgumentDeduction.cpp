#include<iostream>

template<typename T>
void showMe(const T& t){
    std::cout << t << '\n';
}

template <typename T>
struct ShowMe{
    ShowMe(const T& t){
        std::cout << t << '\n';
    }
};

int main(int argc, char const *argv[])
{
    // C++ 11 支持函数模板参数推导
    showMe(5.5);
    showMe(5);

    
    // C++17 支持类模板构造函数参数推导
    ShowMe a(5.5);
    ShowMe b(5);
    return 0;
}
