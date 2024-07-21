#include<iostream>
#include<vector>

namespace Bad{
    struct Number{
        int m;
    };
    // 遵循规则避免使用有常见名称的高可见度无约束模板，将其删除即可
    // template<typename T1 , typename T2>
    // bool operator == (T1 , T2){
    //     return false;
    // }
}


namespace Util{
    bool operator == (int , Bad::Number){
        return true;
    }

    void composeSize(){
        Bad::Number badNumber{5};
        std::vector<int> vec{1 , 2 , 3 , 4 , 5};
        std::cout << std::boolalpha << '\n';
        // 与operator == (int , Bad::Number)理想匹配
        std::cout << "5 == badNumber: " << (5 == badNumber) << '\n';
        // 由于vec.size()返回std::size_type是一个无符号整型
        // 如果匹配operator == (int , Bad::Number)需要进行转换所以并不是最佳匹配
        // 有因为ADL查找非限定函数名operator == (vec.size() , badNumber)
        // 在其参数Number所在命名空间找到了更加适合模板函数，使得泛型相等运算符成为可能的重载集
        // 根据函数匹配规则，vec.size() == badNumber匹配到了operator == (T1 , T2) 
        std::cout << "vec.size() == badNumber: " << (vec.size() == badNumber) << '\n';
        std::cout << '\n';
    }
}

int main(int argc, char const *argv[])
{
    Util::composeSize();
    return 0;
}

