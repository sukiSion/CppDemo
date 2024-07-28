#include<iostream>
#include<type_traits>

template<typename T>
struct removeConst{
    // 通过别名type返回底层类型
    using type = T;
};

template<typename T> 
struct removeConst<const T>{
    // 通过别名type返回底层类型
    using type = T;
};

using std::boolalpha;
using std::cout;
using std::is_same;

int main(int argc, char const *argv[])
{
    cout << is_same<int , removeConst<int>::type>::value << '\n';
    // 针对const类型， removeConst的偏特化模板会期作用
    cout << is_same<int , removeConst<const int>::type>::value << '\n';

    return 0;
}
