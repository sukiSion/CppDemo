#include<condition_variable>
#include<thread>
#include<mutex>
#include<iostream>

std::mutex mut;
std::condition_variable condVar;
bool dataReady = false;

/**
 * 若conVar不设置条件且t2线程先于t1线程执行（提前发送了通知），会导致conVar一直处于等待状态进而产生死锁
 */
void waitingForWork(){
    std::cout << "Waiting " << '\n';
    std::unique_lock<std::mutex> lck(mut);
    condVar.wait(lck , []{return dataReady;});
    std::cout << "Running" << '\n';
}

void setDataReady(){
    {
        std::lock_guard<std::mutex> lck(mut);
        dataReady = true;
    }
    std::cout << "Data prepared" << '\n';
    condVar.notify_one();
}

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    std::thread t1(waitingForWork);
    std::thread t2(setDataReady);

    t1.join();
    t2.join();
    

    std::cout << '\n';
    return 0;
}
