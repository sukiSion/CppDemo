#include<iostream>
#include<cstddef>

// 由于成员函数不依赖于模板参数，故可以放到非模板基类中
template<typename T , std::size_t N>
class Array{
    public:
    Array() = default;
    std::size_t getSize() const{
        return N;
    }
    private:
    T elem[N];  
};

int main(int argc, char const *argv[])
{
    Array<int , 100> arr1;
    std::cout << "arr1.getSize(): " << arr1.getSize() << '\n';
    Array<int , 200> arr2;
    std::cout << "arr2.getSize(): " << arr2.getSize() << '\n';
    return 0;
}
