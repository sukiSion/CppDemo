1、友元的错误：
a．
class snap{
    friend clasp;
    ...
};
class clasp{ ... };
友元声明如下： 
friend class clasp; 
b．
class cuff{
    public:
    void snip(muff &){ ... }
    ...
}
class muff { 
    friend void cuff::snip(muff &); 
    ... 
}; 
这需要一个前向声明，以便编译器能够解释void snip（muff&）： 
    class muff; // forward declaration 
    class cuff { 
    public: 
        void snip(muff &) { ... } 
        ... 
    }; 
    class muff { 
        friend void cuff::snip(muff &); 
        ... 
}; 
c．
class muff{
    friend void cuff: snip(muff &);
    ...
};
class cuff{
    public:
    void snip(muff &){ ... }
};
首先，cuff 类声明应在muff类之前，以便编译器可以理解cuff::snip()。其次，编译器需要muff的
一个前向声明，以便可以理解snip(muff &)。 
    class muff; // forward declaration 
    class cuff { 
    public: 
        void snip(muff &) { ... } 
        ... 
    }; 
    class muff { 
        friend void cuff::snip(muff &); 
        ... 
}; 
2、存在B类只有部分成员是A类的友元且A类只有部分成员是B类的友元吗？
不。为使类A拥有一个本身为类B的成员函数的友元，B的声明必须位于A的声明之前。一个前向声明是不够的，因为这种声明可以告诉A：B是一个类;但它不能指出类成员的名称。同样，如果B拥有一个本身是A的成员函数的友元，则A的这个声明必须位于B的声明之前。这两个要求是互斥的。
3、有以下嵌套类：
class Ribs{
    private:
    class Sauce{
        private:
        int soy;
        int sugar;
        public:
        Sauce(int s1 , int s2): soy(s1) , sugar(s2){}
    };
    ...
}
存在问题：访问类的唯一方法是通过其有接口，这意味着对于Sauce对象，只能调用构造函数来创建一个。其他成员（soy和sugar）在默认情况下是私有的。 
4、throw和return的关系：假设函数f1()调用函数f2()。f2()中的返回语句导致程序执行在函数f1()中调用函数f2()后面的一条语句。throw语句导致程序沿函数调用的当前序列回溯，直到找到直接或间接包含对f2()的调用的try语句块为止。它可能在f1()中、调用f1()的函数中或其他函数中。找到这样的try语句块后，将执行下一个匹配的catch 语句块，而不是函数调用后的语句。 
5、catch块放置的顺序：应按从子孙到祖先的顺序排列catch语句块。
6、比较下面两个行为：
if(ps = dynamic_cast<Superb *>(pg)) ps -> say();
if(typeid(*pg) == typeid(Superb)) ((Superb *)pg) -> say();
第一个行为：如果pg指向一个Superb对象或从Superb派生而来的任何类的对象，则if条件为true。具体地说，如果pg指向Magnificent对象，则if条件也为true。第二个行为：仅当指向Superb对象时，if条件才为true，如果指向的是从Superb派生出来的对象，则if条件不为true。 
7、Dynamic_cast和static_cast的区别：Dynamic_cast 运算符只允许沿类层次结构向上转换，而static_cast运算符允许向上转换和向下转换。static_cast 运算符还允许枚举类型和整型之间以及数值类型之间的转换。