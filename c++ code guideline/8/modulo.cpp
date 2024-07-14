#include<cstddef>
#include<iostream>

/**
 * 对于无符号数：
 * 如果x的值超出最大取值范围，对x的连续加法并不会触发溢出，而是触发一个取模操作
 */
int main(int argc, char const *argv[])
{
    unsigned int max{100000};
    unsigned short x{0};
    std::size_t count{0};
    while(x < max && count < 20){
        std::cout << x << " ";
        x += 10000;
        ++count;
    }
    std::cout << "\n\n";
    return 0;
}
