#include<iostream>
#include<cstddef>

template<class P>
void functionTemplate(P p){
    int* a = p;
}

int main(int argc, char const *argv[])
{
    int* a = 0;
    int* b = NULL;
    int* c = nullptr;

    // 编译器将函数模板中的0推导为int类型    
    // functionTemplate(a);
    // 编译器将函数模板中的0推导为long int类型 
    // functionTemplate(b);
    // 通过模板参数推导保留了它的类型nullptr_t
    functionTemplate(c);
    return 0;
}