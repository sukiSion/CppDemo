#include<cstddef>
#include<iostream>

class ArrayBase{
    protected:
    ArrayBase(std::size_t n): size(n){}
    std::size_t getSize() const{
        return size;
    }
    private:
    std::size_t size;
};

template<typename T , std::size_t N>
class Array: private ArrayBase{
    public:
    Array(): ArrayBase(N){}
    std::size_t getSize() const{
        return ArrayBase::getSize();
    }
    private:
    T data[N];
};

int main(int argc, char const *argv[])
{
    Array<int , 100> arr1;
    std::cout << "arr1.getSize(): " << arr1.getSize() << '\n';
    Array<int , 200> arr2;
    std::cout << "arr2.getSize(): " << arr2.getSize() << '\n';
    return 0;
}
