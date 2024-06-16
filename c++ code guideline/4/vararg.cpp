#include<iostream>
#include<cstdarg>

int sum(int num , ...){
    int sum = 0;
    va_list argPointer; // 保存该函数后面使用到的宏的必要信息
    va_start(argPointer , num); // 启用对变参数函数参数的访问
    for(int i = 0 ; i < num; i++){
        sum += va_arg(argPointer , int); // 访问下一个变参数函数的参数
    }
    va_end(argPointer); // 结束对变参数函数参数的访问
    return sum;
}

int main(int argc, char const *argv[])
{
    std::cout << "sum(1 , 5): " << sum(1 , 5) << '\n';
    std::cout << "sum(3 , 1 , 2 , 3): " << sum(3 , 1 , 2 , 3) << '\n';
    std::cout << "sum(3 , 1 , 2 , 3 , 4): " << sum(3 , 1 , 2 , 3 , 4) << '\n'; 
    // num参数传入的错误
    std::cout << "sum(3 , 1 , 2 , 3.5): " << sum(3 , 1 , 2 , 3.5) << '\n';
    // sum中va_arg对变参数函数参数的访问转换为int
    return 0;
}
