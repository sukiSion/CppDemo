#include<iostream>

struct Immutable{
    // mutable 使得const对象可以调用改变该成员的const成员函数
    mutable int val{12};
    void canNotModify() const{
        val = 13;
    }
};

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    const Immutable immu;
    std::cout << "val: " << immu.val << '\n';
    immu.canNotModify();
    std::cout << "val: " << immu.val << '\n';

    std::cout << '\n';
    return 0;
}
