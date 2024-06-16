constexpr auto gcd(int a , int b){
    while (b != 0){
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(int argc, char const *argv[])
{
    constexpr int i  = gcd(11 , 121); // 会在编译期中求出11， 可以从转成的汇编代码中看出
    
    int a = 11 ;
    int b = 121;
    int j = gcd(a , b);  // 在汇编代码中只是一个函数调用
    return 0;
}
