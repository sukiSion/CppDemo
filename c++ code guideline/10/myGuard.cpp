#include<mutex>
#include<iostream>

/**
 * 该类的行为类似于lock_guard
 * 若没有起名字则会在构造完后直接调用析构函数导致没有锁定
 */
template<typename T>
class MyGuard{
    public:
    explicit MyGuard(T& mutex): myMutex(mutex){
        std::cout << "lock" << '\n';
        myMutex.lock();
    }
    ~MyGuard(){
        myMutex.unlock();
        std::cout << "unlock" << '\n';
    }
    private:
    T & myMutex;
};

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    std::mutex m;
    // 通过给其起名字，可以将临界区保护起来
    MyGuard<std::mutex> myGuard{m};
    std::cout << "CRITICAL SECTION" << '\n';

    std::cout << '\n';
    return 0;
}
