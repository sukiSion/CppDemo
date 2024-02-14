1、适合定义为内联函数的函数：只有一行代码的小型、非递归函数适合作为内联函数。
2、song()函数原型：void song(const char * name , int times);
a、修改原型使times的默认值为1：void song(const char * name , int times = 1);
b、函数定义需要做的修改：没有。只有原型包含默认值的信息
c、能否为name提供默认值“O.My Papa”：没问题，如果保留times的默认值： void song(char * name = "O, My Papa", int times = 1); 
3、编写iquote()重载版本————显示其用双引号括起来的参数：分别用于int、double和string参数：
#include <iostream.h> 
void iquote(int n) 
{ 
    cout << "\"" << n << "\""; 
} 
void iquote(double x) 
{ 
    cout << '"' << x << '"'; 
} 
void iquote(const char * str) 
{ 
    cout << "\"" << str << "\""; 
}
4、存在一个结构：
struct box{
    char market[40];
    float height;
    float width;
    float length;
    float volume;
}
a、编写一个函数，将box结构的引用作为形参，并显示每一个成员的值：
 void show_box(const box & container) 
{ 
    cout << "Made by " << container. maker << endl; 
    cout << "Height = " << container.height << endl; 
    cout << "Width = " << container.width << endl; 
    cout << "Length = " << container.length << endl; 
    cout << "Volume = " << container.volume << endl; 
} 
b、编写一个函数，将box结构的引用作为形参，经volume成员设置为其他三边的乘积
．void set_volume(box & crate) 
   { 
      crate.volume = crate.height * crate.width * crate.length; 
   } 
5、对于程序arrobj.cpp (six/arrobj.cpp) 若让fill()和show()使用引用参数，需要作出的修改
首先，将原型修改成下面这样： 
// function to modify array object 
void fill(std::array<double, Seasons> & pa); 
// function that uses array object without modifying it 
void show(const std::array<double, Seasons> & da); 
接下来，在main()中，将fill()调用改为下面这样： 
fill(expenses); 
函数show()的调用不需要修改。 
接下来，新的fill()应类似于下面这样： 
void fill(std::array<double, Seasons> & pa) // changed 
{ 
    using namespace std; 
    for (int i = 0; i < Seasons; i++) 
    { 
        cout << "Enter " << Snames[i] << " expenses: "; 
        cin >> pa[i]; // changed 
    } 
} 
最后，修改show()的函数头： 
void show(std::array<double, Seasons> & da)
6、下面每个目标是否可以使用默认参数或者函数重载完成，若两者都不能完成则提供合适的函数原型
a、mass(density , volume) 返回密度为density、体积为volume的物体的质量，而mass(density)返回密度为density、体积为1.0立方米的物体的质量。这些值的类型都为double。
默认值：
double mass(double d, double v = 1.0);
函数重载：
double mass(double d, double v); 
double mass(double d); 
b、repeat(10 , "I'm OK")将指定的字符串显示10次，而repeat("But you're kind of stupid")将指定的字符串显示5次
不能使用默认值，因为默认值使从右到左提供的
函数重载：
void repeat(int times, const char * str); 
void repeat(const char * str); 
c、average(3 , 6)返回两个int参数的平均值(int类型)，而average(3.0 , 6.0)返回两个double值的平均值(double)类型
函数重载：
int average(int a, int b); 
double average(double x, double y); 
d、mangle("I'm glad to meet you")根据是将值赋给char变量还是char * 变量，分别返回字符I和指向字符串"I'm mad to gleet you"的指针
不能使用函数重载，因为两个版本的特征标将相同。
7、编写返回两个参数的中较大值的函数模板
template <class T>
T max(T t1, T t2){
    return t1 > t2? t1 : t2;
}
8、利用第四题box结构，提供一个模板具体化，接受两个box参数返回体积较大的一个box
template <>
box max(box b1, box b2){
    return b1.volume > b2.volume ? b1 : b2;
}
9、int g(int x);
...
float m = 5.5f;
float & rm = m;
decltype(m) v1 = m; -> v1 : float
decltype(rm) v2 = m; -> v2 : float &
decltype((m)) v3 = m; -> v3 : float &
decltype(g(100)) v4 -> v4 : int
decltype(2.0 * m) v5 -> v5 : double