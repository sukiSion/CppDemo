#include<iostream>
#include<string>
#include<vector>

template<typename T>
void showInfo(const T& t , const std::string& name){
    // 大小
    std::cout << name << " t.size(): " << t.size() << '\n';
    // 容量
    std::cout << name << " t.capacity(): " << t.capacity() << '\n';
}

int main(int argc, char const *argv[])
{
    std::cout << '\n';
    std::vector<int> vec;
    std::cout << "Maximal size: " << '\n';
    std::cout << "vec.max_size(): " << vec.max_size() << '\n';
    std::cout << '\n';

    std::cout << "Empty vector: " << '\n';
    showInfo(vec , "Vector");
    std::cout << '\n';

    std::cout << "Initialized with five values: " << '\n';
    vec = {1 , 2 , 3 , 4 , 5};
    showInfo(vec , "Vector");
    std::cout << '\n';

    std::cout << "Added four additional values: " << '\n';
    vec.insert(vec.end() , {6 , 7 , 8 , 9});
    showInfo(vec , "Vector");
    std::cout << '\n';

    std::cout << "Resized to 30 values: " << '\n';
    // 调整大小
    vec.resize(30);
    showInfo(vec , "Vector");
    std::cout << '\n';

    std::cout << "Reserved space for at least 1000 values: " << '\n';
    // 调整容量
    vec.reserve(1000);
    showInfo(vec , "Vector");
    std::cout << '\n';

    std::cout << "Shrinked to current size: " << '\n';
    vec.shrink_to_fit();
    showInfo(vec , "Vector");
    return 0;
}
