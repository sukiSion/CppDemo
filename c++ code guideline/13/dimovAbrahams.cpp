#include<iostream>
#include<string>

// getTypeName
// 主模板
template<typename T>
std::string getTypeName(T){
    return "unknown";
}

// 重载模板
// 重载决策找到了合适的指针形式模板，由于存在更合适显式特化，故选择了对应的显式特化
template<typename T>
std::string getTypeName(T*){
    return "pointer";
}

// 重载模板的显式特化
template<>
std::string getTypeName(int*){
    return "int pointer";
}

// getTypeName2
// 同上，只不过调换了重载模板和重载模板的显式特化声明顺序
template<typename T>
std::string getTypeName2(T){
    return "unknown";
}

// 主模板的显式特化
template<>
std::string getTypeName2(int*){
    return "int pointer";
}

// 重载决策忽略了函数模板的特化
// 重载决策找到了合适的指针形式模板，由于没有更合适显式特化，所以只能直接使用该模板
template<typename T>
std::string getTypeName2(T*){
    return "pointer";
}

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    int *p;
    std::cout << "getTypeName(p): " << getTypeName(p) << '\n';
    std::cout << "getTypeName2(p): " << getTypeName2(p) << '\n';

    std::cout << '\n';

    return 0;
}
