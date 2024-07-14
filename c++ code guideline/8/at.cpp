#include<algorithm>
#include<array>
#include<deque>
#include<string>
#include<vector>

template <typename T>
void use(T* , int){}

template<typename T>
void f(T& a){
    if(a.size() < 2) return;
    int n = a.at(0);
    std::array<typename T::value_type , 99> q;
    std::copy(a.begin() + 1 , a.end() , q.begin());
    if(a.size() < 6) return;
    a.at(4) = 1;
    a.at(a.size() - 1) = 2;
    use(a.data() , a.size());
}


int main(int argc, char const *argv[])
{
    std::array<int , 100> arr{};
    f(arr);

    std::array<double , 20> arr2{};
    f(arr2);

    std::vector<double> vec{1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9};
    f(vec);

    std::string myString = "123456789";
    f(myString);

    // 由于f模板函数用于存储在连续内存块的数据，所以不适用于deque
    // std::deque<int> dep{1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};
    // f(dep);
    return 0;
}
