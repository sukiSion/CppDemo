#include<iostream>

template<class... Args>
auto sum(Args... args){
    return (... + args);
}

int main(int argc, char const *argv[])
{
    std::cout << "sum(5): " << sum(1 , 5) << '\n';
    std::cout << "sum(1 , 2 , 3): " << sum(1 , 2 , 3) << '\n';
    std::cout << "sum(1 , 2 , 3 , 4): " << sum(1 , 2 , 3 , 4) << '\n'; 
    std::cout << "sum(1 , 2 , 3.5): " << sum(1 , 2 , 3.5) << '\n'; 
    return 0;
}
