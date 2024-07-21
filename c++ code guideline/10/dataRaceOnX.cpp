/**
 * 由于x不是原子量，以下程序会引起x的数据竞争
 * 由于y是原子量，所以没有问题
 * 在使用CppMem时需要使用CppMem期望的C方言进行重写，最后可以从CppMem中的图中看出x存在数据竞争：
 * Wna x = 2000（写操作x = 2000）和Rna x = 0（读操作x = 0）存在dr（date_race）数据竞争
 */

#include<iostream>
#include<atomic>
#include<thread>

int x = 0;
std::atomic<int> y {0};

void writing(){
    x = 2000;
    y.store(11);
}

void reading(){
    std::cout << y.load() << " " << x << "\n";
}

int main(int argc, char const *argv[])
{
    std::thread thread1(writing);
    std::thread thread2(reading);

    thread1.join();
    thread2.join();
    return 0;
}
