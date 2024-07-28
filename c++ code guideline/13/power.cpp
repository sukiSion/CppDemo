#include<iostream>

// 运行期运行
int power(int m , int n){
    int r = 1;
    for(int k = 1 ; k <= n ; ++k){
        r *= m;
    }
    return r;
}

// 编译期运行
template<int m , int n>
struct Power{
    static const int value = m * Power<m , n - 1>::value; 
};

template<int m>
struct Power<m , 0>{
    static const int value = 1;
};

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    std::cout << "power(2 , 10) = " << power(2 , 10) << '\n';
    std::cout << "Power<2 , 10>::value = " << Power<2 , 10>::value << '\n';

    std::cout << '\n';
    return 0;
}
