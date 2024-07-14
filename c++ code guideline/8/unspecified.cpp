#include<iostream>

void func(int fir , int sec){
    std::cout << "(" << fir << "," << sec << ")" << '\n';
}

int main(int argc, char const *argv[])
{
    int i = 0;
    // 在某些编译器实现下可能输出(0,1)，在某些编译器的实现下可能输出(1,0)
    func(i++ , i++);
    return 0;
}


