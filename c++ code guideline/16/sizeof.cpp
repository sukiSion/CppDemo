#include<array>
#include<iostream>
#include<vector>

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    std::cout << "sizeof(int) = " << sizeof(int) << '\n';
    std::cout << '\n';

    int cArr[10] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};
    std::array<int , 10> cppArr = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};
    std::vector<int> cppVec = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};

    std::cout << "sizeof(cArr) = " << sizeof(cArr) << '\n';
    std::cout << "sizeof(cppArr) = " << sizeof(cppArr) << '\n';
    // vector需要额外的内存来管理堆上的数据
    std::cout << "sizeof(cppVec) = " << sizeof(cppVec) + sizeof(10) * cppVec.capacity();



    std::cout << '\n';

    return 0;
}
