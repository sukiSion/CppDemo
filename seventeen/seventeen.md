1、class Z200 
   { 
   private: 
       int j; 
       char ch; 
       double z; 
   public: 
    Z200(int jv, char chv, zv) : j(jv), ch(chv), z(zv) {} 
   ... 
}; 
double x {8.8}; // or = {8.8} 
std::string s {"What a bracing effect!"}; 
int k{99}; 
Z200 zip{200,'Z',0.67}); 
std::vector<int> ai {3, 9, 4, 7, 1};
2、
#include<iostream>
using namespace std;
double up(double x){
    return 2.0 * x;
}

void r1(const double & rx){
    cout << rx << endl;
}
void r2(double & rx){
    cout << rx << endl;
}
void r3(double && rx){
    cout << rx << endl;
}

int main(int argc, char const *argv[])
{
    double w = 10.0;
    r1(w); // 合法，形参rx指向w
    r1(w + 1); // 合法，形参rx指向一个临时变量，这个变量被初始化为w+1
    r1(up(w)); // 合法，形参rx 指向一个临时变量，这个变量被初始化为up(w)的返回值
    r2(w); // 合法，形参rx指向w
    r2(w + 1); // 非法，因为w+1是一个右值
    r2(up(w)); // 非法，因为up(w)的返回值是一个右值
    r3(w); // 非法，因为右值引用不能指向左值
    r3(w + 1); // 合法，rx 指向表达式w+1的临时拷贝 
    r3(up(w)); // 合法，rx 指向 up(w)的临时返回值
    return 0;
}
3、a、
#include<iostream>
using namespace std;
double up(double x){
    return 2.0 * x;
}

void r1(const double & rx){
    cout << "const double & rx" << endl;
}
void r1(double & rx){
    cout << "double & rx" << endl ;
}


int main(int argc, char const *argv[])
{
    double w = 10.0;
    r1(w);
    r1(w + 1); 
    r1(up(w));
    return 0;
}
输出：
double & rx 
const double & rx 
const double & rx 
b、
#include<iostream>
using namespace std;
double up(double x){
    return 2.0 * x;
}

void r1(double & rx){
    cout << "double & rx" << endl;
}
void r1(double && rx){
    cout << "double & rx" << endl;
}

int main(int argc, char const *argv[])
{
    double w = 10.0;
    r1(w);
    r1(w + 1);
    r1(up(w));
    return 0;
}
输出：
double & rx 
double && rx 
double && rx 
c、
#include<iostream>
using namespace std;
double up(double x){
    return 2.0 * x;
}

void r1(const double & rx){
    cout << "const double & rx" << endl;
}
void r1(double && rx){
    cout << "double & rx" << endl;
}

int main(int argc, char const *argv[])
{
    double w = 10.0;
    r1(w);
    r1(w + 1);
    r1(up(w));
    return 0;
}
输出:
const double & rx 
double && rx 
double && rx 
4、特殊的成员函数:
默认构造函数、复制构造函数、移动构造函数、析构函数、复制赋值运算符和移动赋值运算符
原因：编译器将根据情况自动提供它们的默认版本
5、在转让数据所有权（而不是复制数据）可行时，可使用移动构造函数，但对于标准数组，没有转让其所有权的机制。如果Fizzle使用指针和动态内存分配，则可将数据的地址赋给新指针，以转让其所有权。
6、
#include<iostream>
template<typename T>
void show2(double x , T & fp){
    std::cout << x << " -> " << fp(x) << '\n';
}
double f1(double x){
    return 1.8 * x + 32;
}

int main(int argc, char const *argv[])
{
    show2(18.0 , f1);
    return 0;
}
转化为lambda:
#include<iostream>
template<typename T>
void show2(double x , T fp){
    std::cout << x << " -> " << fp(x) << '\n';
}

int main(int argc, char const *argv[])
{
    show2(18.0, [](double x){return 1.8*x + 32;});
    return 0;
}
7、
#include <iostream>
#include <array>
const int Size = 5;
template <typename T>
void sum(std::array<double, Size> a, T &fp);
class Adder{
    private:
    double tot;
    public:
    Adder(double q = 0){}
    void operator()(double w){
        tot += w;
    }
    double tot_v() const {return tot;}
};

int main(int argc, char const *argv[])
{
    double total = 0.0;
    Adder ad(total);
    std::array<double, Size> temp_c = {32.1, 34.3, 37.8, 35.2, 34.7}; 
    sum(temp_c, ad);
    total = ad.tot_v(); 
    std::cout << "total: " << ad.tot_v() << '\n';
    return 0;
}

template <typename T>
void sum(std::array<double, Size> a, T &fp){
    for (auto pt = a.begin(); pt != a.end(); ++pt){
        fp(*pt);
    }
}
转为lambda:
#include <iostream>
#include <array>
const int Size = 5;
template <typename T>
void sum(std::array<double, Size> a, T fp);

int main(int argc, char const *argv[])
{
    double total = 0.0;
    std::array<double, Size> temp_c = {32.1, 34.3, 37.8, 35.2, 34.7}; 
    sum(temp_c, [&total](double x){
        total += x;
    });
    std::cout << "total: " << total << '\n';
    return 0;
}

template <typename T>
void sum(std::array<double, Size> a, T fp){
    for (auto pt = a.begin(); pt != a.end(); ++pt){
        fp(*pt);
    }
}