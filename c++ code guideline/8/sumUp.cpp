#include<iostream>
#include<numeric>
#include<vector>

int main(int argc, char const *argv[])
{
    std::vector<int> vec{1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};

    // 不好，直接对容器迭代非常容易出错，容易产生“差一错误”
    // “差一错误”：一种常见的安全编码错误，指边界条件写错造成的循环次数差一的错误。最常见的原因是不小心把<和<=写错了
    int sum1 = 0;
    for(int i = 0 ; i < vec.size() ; ++i) sum1 += vec[i];
    std::cout << sum1 << '\n';

    // 好一点，基于范围的for循环进行隐式迭代安全得多
    int sum2 = 0;
    for(auto v: vec) sum2 += v;
    std::cout << sum2 << '\n';

    // 最好，使用STL算法std::accumulate明表达了代码的意图
    auto sum3 = std::accumulate(vec.begin() , vec.end() , 0);
    std::cout << sum3 << '\n';
    return 0;
}
