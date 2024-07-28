#include<iostream>
#include<type_traits>

template<typename T>
T gcd(T a , T b){
    static_assert(std::is_integral_v<T> , "T should be an integral type!");
    if(b == 0){
        return a;
    }else{
        return gcd(b , a % b);
    }
}

int main(int argc, char const *argv[])
{
    std::cout << gcd(100 , 33) << '\n';
    std::cout << gcd(3.5 , 4.0) << '\n';
    std::cout << gcd("100" , "10") << '\n';
    return 0;
}
