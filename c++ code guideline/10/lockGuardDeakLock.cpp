#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

struct CriticalData{
  std::mutex mut;
};

void deadLock(CriticalData& a, CriticalData& b){
    std::lock_guard<std::mutex> guard1(a.mut);
    std::cout << "Thread: " << std::this_thread::get_id() << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::lock_guard<std::mutex> guard2(b.mut);
    std::cout << "Thread: " << std::this_thread::get_id() << '\n';
}

// 1、可将std::unique_lock和std::lock一起使用，并且使用std::defer_lock标签
// std::unique_lock可以在不锁定的情况下获取互斥量，类似std::lock_guard可以管理锁的生命周期
// std::lock可以接受任意数量的参数，并且保证不产生死锁
void deadLock1(CriticalData& a, CriticalData& b){
    std::unique_lock<std::mutex> guard1(a.mut , std::defer_lock);
    std::cout << "Thread: " << std::this_thread::get_id() << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::unique_lock<std::mutex> guard2(b.mut , std::defer_lock);
    std::cout << "Thread: " << std::this_thread::get_id() << '\n';
    std::lock(guard1 , guard2);
}

// C++17更加简单，直接使用作用域锁std::scoped_lock即可
void deadLock2(CriticalData& a, CriticalData& b){
    std::scoped_lock(a.mut , b.mut);
}

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    CriticalData c1;
    CriticalData c2;

    // 由于以不同顺序的获取互斥量而导致死锁
    // 解决死锁的最简单方法是以原子方式锁定两个互斥量
    std::thread t1([&]{deadLock1(c1,c2);});
    std::thread t2([&]{deadLock1(c2,c1);});
    
    t1.join();
    t2.join();

    std::cout << '\n';
    return 0;
}
