#include<future>

// id++是一个读-修改-写操作
// 读、修改、写操作是原子的，但是读-修改-写操作不是原子，结果就是id很可能不唯一
int getUniqueId(){
    static int id = 1;
    return id++;
}

int main(int argc, char const *argv[])
{
    auto fut1 = std::async([]{return getUniqueId(); });
    auto fut2 = std::async([]{return getUniqueId(); });
    auto id = fut1.get();
    auto id2 = fut2.get();
    return 0;
}
