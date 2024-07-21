#include<exception>
#include<iostream>
#include<future>
#include<thread>
#include<utility>

struct Div{
    // 重载()，作为三元函数符，作为函数符传入thread进行构造时额外传入三个参数
    void operator()(std::promise<int> intPromise , int a , int b) const{
        try{
            if(b == 0){
                std::string err = "Illegal dicision by zero: " + std::to_string(a) + "/" + std::to_string(b);
                throw std::runtime_error(err);
            }
            // promise.set_value 保存共享状态
            // 当调用future.get()则获取promise中保存的状态
            intPromise.set_value(a / b);
        }catch(...){
            // 使用set_exception设置异常后当调用future.get()时会重新抛出异常，相关期值必须对其进行处理
            intPromise.set_exception(std::current_exception());
        }
    }
};

void executeDivision(int nom , int denom){
    std::promise<int> divPromise;
    std::future<int> divResult = divPromise.get_future();

    Div div;
    std::thread divThread(div , std::move(divPromise) , nom , denom);
    
    // 获取结果或者异常
    try{
        std::cout << nom << "/" << denom << " = " << divResult.get() << '\n';
    }catch(std::runtime_error& e){
        std::cout << e.what() << '\n';
    }

    divThread.join();
}

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    executeDivision(20 , 0);
    executeDivision(20 , 10);

    std::cout << '\n';
    return 0;
}
