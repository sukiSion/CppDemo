#include<algorithm>
#include<iostream>
#include<vector>

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    std::vector<int> inVec{1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};
    std::for_each(
        inVec.begin(),
        inVec.end(),
        // sum为lambda表法式的状态，C++14支持所谓的lambda初始化捕获
        // sum变量只在lambda的作用域内有效
        // lambda表达式默认为const，要改变lambda中的状态（sum）需要声明为mutable
        // 这样可以将值加到sum上
        [sum = 0](int i) mutable{
            sum += i;
            std::cout << sum << " ";
        }
    );


    std::cout << '\n';
    return 0;
}
