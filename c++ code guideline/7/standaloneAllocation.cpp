#include<iostream>
#include<memory>

struct MyInt{
    explicit MyInt(int myInt): i(myInt){}
    ~MyInt(){
        std::cout << "Goodbye from " << i << '\n';
    }
    int i;
};

int main(int argc, char const *argv[])
{
    std::cout << '\n';
    MyInt * myInt = new MyInt(2011);

    // 由于uniq1和uniq2都是myInt的所有者，所以会发生两次释放，导致第二次释放发生未定义行为   
    std::unique_ptr<MyInt> uniq1 = std::unique_ptr<MyInt>(myInt);
    // std::unique_ptr<MyInt> uniq2 = std::unique_ptr<MyInt>(myInt);

    // 对于这种情况可以使用std::make_unique进行规避
    std::unique_ptr<MyInt> uniq3 = std::make_unique<MyInt>(2011);

    std::cout << '\n';
    return 0;
}


