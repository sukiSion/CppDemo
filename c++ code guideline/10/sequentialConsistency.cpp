#include<atomic>
#include<iostream>
#include<thread>

std::atomic<int> x{0};
std::atomic<int> y{0};

// 由于序列一致性x.store(2000); 发生在y.store(11);之前
// 所以一定不可能存在x = 0 而y = 11的情况
void writing(){
    x.store(2000); 
    y.store(11);
}

void reading(){
    std::cout << y.load() << " ";
    std::cout << x.load() << "\n";
}

int main(int argc, char const *argv[])
{
    std::thread thread1(writing);
    std::thread thread2(writing);
    thread1.join();
    thread2.join();
    return 0;
}
