#include<iostream>

long double sum_value(){return 0;}

template<class T , class... Args>
long double sum_value(T value ,  const Args & ... args){
    long double sum = value;
    return sum + sum_value(args...);
}

int main(int argc, char const *argv[])
{
    int n = 14;
    double x = 2.71828;
    long y = 100000;
    char ch = 'x';
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield); 
    std::cout << "sum1: " << sum_value(n, x, y)<< std::endl;
    std::cout << "sum2: " << sum_value(n, x, y, ch, 'K', 66, 33.67) << std::endl;
    std::cout << "Done." << std::endl;
    return 0;
}
