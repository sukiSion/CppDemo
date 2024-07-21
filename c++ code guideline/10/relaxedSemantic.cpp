#include<atomic>
#include<iostream>
#include<thread>

std::atomic<int> x{0};
std::atomic<int> y{0};

// 出现的结果取决于硬件
// 由于宽松语义只保证对原子量操作的原子性且操作不在同一原子量上，所有x = 0 而y = 11成了可能
void writing(){
    x.store(2000 , std::memory_order_relaxed); 
    y.store(11 , std::memory_order_relaxed);
}

// 同上，可能会看到先输出x然后输出y
void reading(){
    std::cout << y.load(std::memory_order_relaxed) << " ";
    std::cout << x.load(std::memory_order_relaxed) << "\n";
}

int main(int argc, char const *argv[])
{
    std::thread thread1(writing);
    std::thread thread2(writing);
    thread1.join();
    thread2.join();
    return 0;
}