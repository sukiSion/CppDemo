1、class RQ1{
    private:
    char * st;
    public:
    RQ1(){st = new char[1]; strcpy(st , "");}
    RQ1(const char * s){
        st = new char[strlen(s) + 1];
        strcpy(st , s);
    }
    RQ1(const RQ1 & rq){
        st = new char[strlen(s) + 1];
        strcpy(st , rq.st);
    }
    ~RQ1(){delete[] st;}
    RQ & operator=(const RQ & rq);
};
将char数组替换为string可以去掉：析构函数、复制构造函数、赋值运算符
2、string优于C风格字符串的地方：可以将一个string 对象赋给另一个。string 对象提供了自己的内存管理功能，所以一般不需要担心字符串超出存储容量。
3、将string转大写
#include <string> 
#include <cctype>
#include<iterator>
using namespace std; 
void ToUpper(string & str) 
{ 
    for (char & ch: str){
        ch = toupper(ch); 
    } 
}
4、
auto_ptr<int> pia= new int[20]; // 错误，new 数组需要使用unique_ptr，不能使用auto_ptr和shared_ptr
auto_ptr<string>(new string);   // 错误，没有声明名称
int rigue = 7; 
auto_ptr<int>(&rigue);           // 错误，该指针管理的不是堆内存
auto_ptr dbl (new double);       // 错误，缺少模板参数<double>
5、由于栈是先进后出只允许在一段进行操作，当我们需要的数据在栈的深处时需要将目标以上数据全部出栈才行
6、由于set不能存储相同值（值就是键）所以不能用来记录成绩，因为成绩有可能相同
7、没有使用指针代替迭代器的原因：使用迭代器使得能够使用[接口类似于指针的对象]遍历不以数组方式组织的数据，如双向链表中的数据。
8、STL仅定义迭代器基类而使用继承来派生其他迭代器类型的类，并根据这些迭代器类来表示算法的原因：STL方法使得可以将STL函数用于指向常规数组的常规指针以及指向STL容器类的迭代器，因此提高了通用性。 
9、vevtor比常规数据方便的原因：可以将一个vector对象赋给另一个。vector管理自己的内存，因此可以将元素插入到矢量中，并让它自动调整长度。使用at()方法，可以自动检查边界。  
10、当vector转list后，由于list没有随机访问迭代器，所以无法使用random_shuffle()，此时可以将list复制到一个矢量打乱后复制回去，而list有sort()方法可以替代STL通用函数sort(),list的sort类方法有一个重载版本：不传参数按照默认排序的版本和传入一个谓词函数的版本
11、bool bo = TooBig<int>(10)(15): 将10绑定到TooBig类中，也就是作为对照值，而15则是利用了TooBig重载的operator()()运算符，该方法返回bool，这里相当于调用了toobig.operator()(15){}，由于15 > 10 ，所以赋给bo的值为true