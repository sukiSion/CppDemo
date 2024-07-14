#include<forward_list>
#include<chrono>
#include<vector>
#include<deque>
#include<iomanip>
#include<iostream>
#include<list>
#include<string>
#include<numeric>
#include<random>

const int SIZE = 100'000'000;

template<typename T>
void SumUp(T& t , const std::string& cont){
    std::cout << std::fixed << std::setprecision(10);

    auto begin = std::chrono::steady_clock::now();
    std::size_t res = std::accumulate(t.begin() , t.end() , 0LL);
    std::chrono::duration<double> last = std::chrono::steady_clock::now() - begin;
    std::cout << '\n';
    
    std::cout << "time: " << last.count() << '\n';
    std::cout << "res: " << res << '\n';
    std::cout << '\n';

    std::cout << '\n';
}

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    std::random_device seed;
    std::mt19937 engine(seed());
    // 0 - 100的随机数
    std::uniform_int_distribution<int> dist(0 , 100);
    std::vector<int> randNum;
    randNum.reserve(SIZE);
    // 创建一亿个随机数放入vector
    // randNum为随机数列表
    for(int i = 0 ; i < SIZE ; ++i){
        randNum.push_back(dist(engine));
    }
    {
        // 使用randNum构造一个随机数vecotr
        std::vector<int> vec(randNum.begin() , randNum.end());
        SumUp(vec , "std::vector<int>");
    }
    {
        // 使用randNum构造一个随机数deque
        std::deque<int> deq(randNum.begin() , randNum.end());
        SumUp(deq , "std::deque<int>");
    }
    {
        // 使用randNum构造一个随机数list
        std::list<int> lst(randNum.begin() , randNum.end());
        SumUp(lst , "std::list<int>");
    }
    {
        // 使用randNum构造一个随机数forward_list
        std::forward_list<int> forwardLst(randNum.begin() , randNum.end());
        SumUp(forwardLst , "std::forward_list<int>");
    }
    return 0;
}
