#include<utility>
#include<future>
#include<iostream>

void waitingForWork(std::future<void> future){
    std::cout << "Waiting " << '\n';
    // 等待诺值的通知
    future.wait();
    std::cout << "Running " << '\n';
}

void setDataReady(std::promise<void> prom){
    std::cout << "Data prepared" << '\n';
    // 通知期值
    prom.set_value();
}

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    std::promise<void> sendReady;
    // 获取promise的期值future
    auto fut = sendReady.get_future();

    // promise所有权转到线程t1
    std::thread t1(waitingForWork , std::move(fut));
    // future所有权转到线程t2
    std::thread t2(setDataReady , std::move(sendReady));

    std::cout << '\n';
    return 0;
}
