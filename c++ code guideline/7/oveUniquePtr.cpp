#include<iostream>
#include<algorithm>
#include<memory>
#include<utility>
#include<vector>

void takeUniquePtr(std::unique_ptr<int> uniqPtr){
    std::cout << "*uniqPtr: " << *uniqPtr << '\n';  
}

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    auto uniqPtr1 = std::make_unique<int>(2011);
    // 由于所有权转移到了takeUniquePtr函数中形参中
    // 所以经过takeUniquePtr调用后uniqPtr被释放掉了
    takeUniquePtr(std::move(uniqPtr1));
    
    auto uniqPtr2 = std::make_unique<int>(2014);
    auto uniqPtr3 = std::make_unique<int>(2017);

    std::vector<std::unique_ptr<int>> vecUniqPtr{};
    vecUniqPtr.push_back(std::move(uniqPtr2));
    vecUniqPtr.push_back(std::move(uniqPtr3));
    vecUniqPtr.push_back(std::make_unique<int>(2020));
    std::cout << '\n';

    std::for_each(vecUniqPtr.begin() , vecUniqPtr.end() , [](std::unique_ptr<int>& uniqPtr){
        std::cout << *uniqPtr << '\n';
    });

    std::cout << '\n';
    return 0;
}
