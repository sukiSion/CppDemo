/**
 * 两个线程交替将一个bool值设置为true或者false
 * 一个线程将该值设置为true并通知另一个线程
 * 另一个线程将该值这只为false并通知原线程
 * 该程序存在数据竞争：counter的写入和读取是不同步的
 */

#include<condition_variable>
#include<iostream>
#include<thread>

bool dataReady = false;

std::mutex mut;
std::condition_variable condVar1;
std::condition_variable condVar2;

int counter = 0;
int COUNTLIMIT = 50;

void setTure(){
    while(counter <= COUNTLIMIT){
        std::unique_lock<std::mutex> lck(mut);
        condVar1.wait(lck , []{return dataReady == false;});
        dataReady = true;
        ++counter;
        std::cout << dataReady << '\n';
        condVar2.notify_one();
    }
}

void setFalse(){
    while(counter < COUNTLIMIT){
        std::unique_lock<std::mutex> lck(mut);
        condVar2.wait(lck , []{return dataReady == true;});
        dataReady = false;
        std::cout << dataReady << '\n';
        condVar1.notify_one();
    }
}

int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha << '\n';
    std::cout << "Begin: " << dataReady << '\n';
    std::thread t1(setTure);
    std::thread t2(setFalse);
    t1.join();
    t2.join();
    dataReady = false;
    std::cout << "End: " << dataReady << '\n';
    std::cout << '\n';
    return 0;
}
