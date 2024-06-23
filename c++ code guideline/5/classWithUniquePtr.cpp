#include<memory>

struct MyClass
{
    std::unique_ptr<int> uniPtr = std::make_unique<int>(2011);
};


int main(int argc, char const *argv[])
{
    MyClass myClass;
    // 由于std::unique_Ptr支持六大特殊成员函数，所以禁用拷贝操作
    // MyClass myClass2(myClass);
    MyClass myClass3;
    // MyClass3 = myClass;
    return 0;
}
