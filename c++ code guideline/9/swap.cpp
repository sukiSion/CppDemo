#include<algorithm>
#include<iostream>
#include<utility>

// std::move返回一个右值，一个const左值引用可以绑定到一个右值上
// 而拷贝构造函数或拷贝赋值运算符需要一个const左值引用
template<typename T>
void swap(T& a , T& b) noexcept{
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

// 若该类有一个接受右值引用的移动构造函数或移动赋值运算符，那么这两个函数的优先级都将高于拷贝构造函数
// 和拷贝赋值运算符
class BigArray{
    public:
    explicit BigArray(std::size_t sz): size(sz) , data(new int[size]){}
    BigArray(const BigArray& other): size(other.size) , data(new int[other.size]){
        std::cout << "Copy constructor" << '\n';
        // 缺陷3：该表达式同时用在了拷贝构造函数和拷贝赋值运算符中
        std::copy(other.data , other.data + size , other.data);
    }

    BigArray& operator = (const BigArray& other){
        std::cout << "copy assignment" << '\n';
        // 缺陷1：大多数情况下自赋值不会发生，但检查会一直执行
        if(this != &other){
            delete [] data;
            size = other.size;
            // 缺陷2：如果内存分配失败，size是错误，并且data被删除
            // 只确保了在异常出现后不会发生内存泄漏
            data = new int[size];
            std::copy(other.data , other.data + size , other.data);
        }
        return *this;
    }
    // 缺陷2解决办法：
    // 按值传参，不用自检查
    BigArray& operator=(BigArray other){
        swap(*this , other);
        return *this;
    }
    ~BigArray(){
        delete[] data;
    }
    private:
    std::size_t size;
    // 更好的方式：使用std::vector代替C数组
    int * data;
};

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    BigArray bigArr1(2011);
    BigArray bigArr2(2017);
    swap(bigArr1 , bigArr2);
    std::cout << '\n';
    return 0;
}
