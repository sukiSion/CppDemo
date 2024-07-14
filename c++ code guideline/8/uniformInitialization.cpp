#include<map>
#include<vector>
#include<string>

class Array{
    private:
    const int myData[5];
    public:
    Array(): myData{1 , 2 , 3 , 4 , 5}{}
};

class MyClass{
    public:
    int x;
    double y;
};

class MyClass2{
    public:
    MyClass2(int fir , double sec): x{fir} , y{sec}{}
    private:
    int x;
    double y;
};


int main(int argc, char const *argv[])
{
    // 标准容器的直接初始化
    int intArray[] = {1 , 2 , 3 , 4 , 5};
    std::vector<int> intArray1{1 , 2 , 3 , 4 , 5};
    std::map<std::string , int> myMap{
        {"Scott" , 1976},
        {"Dijkstra" , 1972}
    };

    Array arr;
    
    // 任意对象的默认初始化
    int i{};  // 初始化为0
    std::string s{}; // 初始化为""
    std::vector<float> v{}; // 初始化为空vector
    double d{}; // 初始化为0.0

    // 直接初始化有公共成员的对象
    MyClass myClass{2011 , 3.14};
    MyClass myClass1 = {2011 , 3.14};

    // 利用构造函数初始化对象
    MyClass2 myClass2{2011 , 3.14};
    MyClass2 myClass3{2011 , 3.14};
    return 0;
}

