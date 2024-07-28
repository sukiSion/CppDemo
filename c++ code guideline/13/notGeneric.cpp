#include<deque>
#include<vector>
#include<list>

template<typename Cont>
void justInterate(const Cont& cont){
    const auto itEnd = cont.end();
    // vector和deque使用的是随访问迭代器
    // 由于list使用的是双向迭代器，所以不支持比较操作 < 
    // 可以使用 != 来作为结束条件
    // 这里最好使用STL标准库提供的循环算法，而不是手动显式循环
    for(auto it = cont.begin() ; it != itEnd ; ++it){
        // 处理事务
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> vectInt{1 , 2 , 3 , 4 , 5};
    justInterate(vectInt);

    std::deque<int> deqInt{1 , 2 , 3 , 4 , 5};
    justInterate(deqInt);

    std::list<int> listInt{1 , 2 , 3 , 4 , 5};
    justInterate(listInt);
    return 0;
}
