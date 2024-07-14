#include<iostream>
/**
 * 对于有符号数：
 * 如果x的值超出最大取值范围，对x的连续加法会触发溢出（上溢）
 */
int main(int argc, char const *argv[])
{
    int max{100000};
    short x{0};
    std::size_t count{0};
    while(x < max && count < 20){
        std::cout << x << " ";
        x += 10000;
        ++count;
    }
    std::cout << "\n\n";
    return 0;
}