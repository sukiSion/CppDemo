#include<algorithm>
#include<iostream>
#include<vector>

// 将函数调用的结果直接存储在函数对象中
class SumMe{
    int sum{0};
    public:
    SumMe() = default;
    void operator()(int x){
        sum += x;
    }

    int getSum() const{
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> inVec{1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};
    // for_each能够返回传入可调用对象
    // 而对象中刚好保存和函数调用的结果（状态）
    SumMe sumMe = std::for_each(inVec.begin() , inVec.end() , SumMe());
    std::cout << '\n';
    std::cout << "Sum of inVec = " << sumMe.getSum() << '\n';
    std::cout << '\n';

    return 0;
}
