/**
 * 由于没有地方释放tmpInt，所以该程序会内存泄漏
 * 可以将tmpInt改成共享指针，并使showNumber接收一个共享指针的参数
 */

#include<iostream>
#include<thread>
#include<memory>

using namespace std::literals::chrono_literals;

struct MyInt{
    int val{2017};
    ~MyInt(){
        std::cout << "Goodbye" << '\n';
    }
};

void showNumber(std::shared_ptr<MyInt> myInt){
    std::cout << myInt->val << '\n';
}

// void showNumber(const MyInt* myInt){
//     std::cout << myInt->val << '\n';
// }

void threadCreator(){
    std::shared_ptr<MyInt> tmpInt = std::make_shared<MyInt>() ;
    std::thread t1(showNumber , tmpInt);
    std::thread t2(showNumber , tmpInt);
    t1.detach();
    t2.detach();
}

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    threadCreator();
    std::this_thread::sleep_for(1s);

    std::cout << '\n';
    return 0;
}
