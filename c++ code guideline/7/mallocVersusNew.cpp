#include<iostream>
#include<string>

struct Record{
    explicit Record(const std::string& na):name(na){}
    std::string name;
};

int main(int argc, char const *argv[])
{
    Record* p1 = static_cast<Record*>(malloc(sizeof(Record)));
    // 由于malloc没有调用构造函数，所以p1指向的Record对象中name变量没有赋值导致未定义行为
    std::cout << p1->name << std::endl;

    auto p2 = new Record("Record");
    std::cout << p2->name << std::endl;
    return 0;
}
