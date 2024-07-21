#include<iostream>
#include<thread>
#include<string>


/**
 * 两个问题：
 * 1、线程t使用了超出作用域的变量s，此时外围作用域内的变量可能不再有效
 * 2、std::cout具有静态存储器，std::cout的生存期将随着进程的结束而结束此时线程t可能会使用std::cout
 */
void func(){
    std::string s{"C++11"};
    std::thread t([&s]{std::cout << "s" << '\n';});
    t.detach();
}

int main(int argc, char const *argv[])
{
    func();
    return 0;
}
