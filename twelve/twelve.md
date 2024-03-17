1、派生类可以继承：基类的公有成员成为派生类的公有成员。基类的保护成员成为派生类的保护成员。基类的私有成员被继承，但不能直接访问
2、派生类不能继承：不能继承构造函数、析构函数、赋值运算符和友元
3、赋值语句返回void时：赋值能够赋值成功，但是无法进行连锁赋值，因为返回为void，返回对象时：执行速度变慢，需要返回复制对象
4、创建派生对象：先构造基类后构造派生；删除派生对象：先析构派生后析构基类
5、派生类即使没有新增任何数据成员都需要添加构造函数：每个类都必须有自己的构造函数。如果派生类没有添加新成员，则构造函数可以为空，但必须存在。
6、派生类和基类定义了同名方法：当派生类调用该方法时：只调用派生类方法。它取代基类定义。仅当派生类没有重新定义方法或使用作用域解析运算符时，才会调用基类方法。然而，应把将所有要重新定义的函数声明为虚函数。
7、派生类应定义复制运算符的情况：如果派生类构造函数使用new或new[ ]运算符来初始化类的指针成员，则应定义一个赋值运算符。更普遍地说，如果对于派生类成员来说，默认赋值不正确，则应定义赋值运算符 。
8、可以将派生类对象地址赋给基类地址，反之只有通过显式类型转换，才可以将基类对象的地址赋给派生类指针（向下转换），而使用这样的指针不一定安全。
9、可以将派生类对象赋给基类对象。对于派生类中新增的数据成员都不会传递给基类对象。然而，程序将使用基类的赋值运算符。仅当派生类定义了转换运算符（即包含将基类引用作为唯一参数的构造函数）或使用基类为参数的赋值运算符时，相反方向的赋值才是可能的。
10、C++允许基类引用指向从该基类派生而来的任何类型
11、派生对象都够作为参数在按值传递的方法中使用：按值传递对象将调用复制构造函数。由于形参是基类对象，因此将调用基类的复制构造函数。复制构造函数以基类引用为参数，该引用可以指向作为参数传递的派生对象。最终结果是，将生成一个新的基类对象，其成员对应于派生对象的基类部分。
12、按引用效率更高的原因：按引用（而不是按值）传递对象，这样可以确保函数从虚函数受益。另外，按引用（而不是按值）传递对象可以节省内存和时间，尤其对于大型对象。按值传递对象的主要优点在于可以保护原始数据，但可以通过将引用作为const类型传递，来达到同样的目的。
13、Corporation为基类，PublicCorporation为派生类，他们都具有head()函数：有一个Corporation类型指针指向PublicCorporation, 当通过该指针调用head()时：head为虚则调用派生类的方法，非虚常规则调用基类方法
14、下面有一个基类和派生类：
class Kitchen{
    private:
    double kit_sq_ft;
    public:
    Kitchen(){kit_sq_ft = 0.0;}
    virtual double area() const{return kit_sq_ft * kit_sq_ft;}
}

class House: public Kitchen{
    private:
    double all_sq_ft;
    public:
    House() {all_sq_ft += kit_sq_ft};
    double area(const char *s) const{cout << s; return all_sq_ft;}
}
存在问题：
1) 不符合is-a模型
2) House中的area()定义隐藏了area()的Kitchen 版本，因为这两个方法的特征标不同