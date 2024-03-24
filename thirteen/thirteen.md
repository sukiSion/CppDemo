1、
基类：Class Bear     派生类：class PolarBear       私有&公有：公有，北极熊是一种熊 
基类：class Kitchen  派生类：class Home            私有&公有：私有，家里有厨房 
基类：class Person   派生类：class Programmer      私有&公有：公有，程序员是一种人
基类：class Person   派生类：class HorseAndJockey  私有&公有：私有，马和驯马师的组合中包含一个人 
基类：class Person   派生类：class Automobile      私有&公有：公有，司机是一个人
基类：class Person   派生类：class Driver          私有&公有：私有，司机有一辆汽车 
2、class Frabjous {
    private:
    char fab[20];
    public:
    Frabjous(const char * s = "C++") : fab(s) { }
    virtual void tell() { cout << fab; }
};
class Gloam {
    private:
    int glip;
    Frabjous fb;
    public:
    Gloam(int g = 0, const char * s = "C++");
    Gloam(int g, const Frabjous & f);
    void tell();
};
假设Gloam版本的tell()应显示glip和fb的值，请为这3个Gloam方法提供定义。
Gloam(int g = 0, const char * s = "C++"):glip(g), Frabjous(s){}
Gloam(int g, const Frabjous & f):glip(g), Frabjous(f){}
void tell(){fb.tell(); cout << glip << endl;}
3、class Frabjous {
    private:
    char fab[20];
    public:
    Frabjous(const char * s = "C++") : fab(s) { }
    virtual void tell() { cout << fab; }
};
class Gloam : private Frabjous{
    private:
    int glip;
    public:
    Gloam(int g = 0, const char * s = "C++");
    Gloam(int g, const Frabjous & f);
    void tell();
};
假设Gloam版本的tell()应显示glip和fb的值，请为这3个Gloam方法提供定义。
Gloam(int g = 0, const char * s = "C++"): glip(g) , Frabjous(s){}
Gloam(int g, const Frabjous & f): glip(g) , Frabjous(f){}
void tell(){Frabjous::tell(); cout << glip << endl;}
4、class Stack<Worker *>{
    private:
    static const int MAX = 10;
    Worker * items[MAX];
    int top;
    public:
    Stack(){
        top = 0;
    }
    bool isEmpty();
    bool isFull();
    bool push(const Worker * & item);
    bool pop(Worker * & item);
};
5、string对象数组：ArrayTP<string> sa; 
double数组栈：StackTP< ArrayTP<double> > stck_arr_db;
指向Worker对象的指针的栈数组： ArrayTP< StackTP<Worker *> > arr_stk_wpr;
ArratTP<int , 10> sums;
ArratTP<double , 10> aves;
ArratTP<ArratTP<int , 5> , 10> twodee;
上述一共生成4个模板：：ArrayTP<int, 10>、ArrayTP<double, 10>、ArrayTP<int, 5>和 Array<ArrayTP 
<int, 5>, 10>
6、虚基类和非虚基类的区别：．如果两条继承路线有相同的祖先，则类中将包含祖先成员的两个拷贝。将祖先类作为虚基类可以解决这种问题。