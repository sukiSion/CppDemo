#include<iostream>

int shadow(bool cond){
    int d = 0;
    if(cond){
        d = 1;
    }else{
        int d = 2; // 声明在本地作用域的d从而隐藏了父作用域里的d
        d = 3; // 修改的是本地作用域里的d
    }
    return d;
}


int main(int argc, char const *argv[])
{
    std::cout << "\n";

    std::cout << "shadow(true): " << shadow(true) << '\n';
    std::cout << "shadow(false): " << shadow(false) << '\n';

    std::cout << "\n";
    return 0;
}
