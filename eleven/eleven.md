1、有以下String：
class String
{
   private:
      char * str;  //points to string allocated by new
      int len;    //holds length of string
   //...
};
a. String ::String() {} 
问题：语法是正确的，但该构造函数没有将str 指针初始化。该构造函数应将指针设置成NULL或使用new [ ]来初始化它。 
b. String:: String (const char* s)
{
     str = s:
     len = strlen(s);
} 
问题：该构造函数没有创建新的字符串，而只是复制了原有字符串的地址。它应当使用 new [ ]和strcpy()。
c.String: :String (const char* s)
{
     strcpy(str, s);
     len = strlen(s);
} 
问题：它复制了字符串，但没有给它分配存储空间，应使用new char[len + 1]来分配适当数量的内存。
2、定义一个类并且指针成员使用new初始化，存在的问题：
首先，当这种类型的对象过期时，对象的成员指针指向的数据仍将保留在内存中，这将占用空间，同时不可访问，因为指针已经丢失。可以让类析构函数删除构造函数中new分配的内存，来解决这种问题。其次，析构函数释放这种内存后，如果程序将这样的对象初始化为另一个对象，则析构函数将试图释放这些内存两次。这是因为将一个对象初始化为另一个对象的默认初始化，将复制指针值，但不复制指向的数据，这将使两个指针指向相同的数据。解决方法是，定义一个复制构造函数，使初始化复制指向的数据。第三，将一个对象赋给另一个对象也将导致两个指针指向相同的数据。解决方法是重载赋值运算符，使之复制数据，而不是指针。
3、编译器会自动生成的类方法：
3．C++自动提供下面的成员函数： 
1) 如果没有定义构造函数，将提供默认构造函数。 
2) 如果没有定义复制构造函数，将提供复制构造函数。 
3) 如果没有定义赋值运算符，将提供赋值运算符。 
4) 如果没有定义析构函数，将提供默认析构函数。 
5) 如果没有定义地址运算符，将提供地址运算符。 
默认构造函数不完成任何工作，但使得能够声明数组和未初始化的对象。默认复制构造函数和默认赋值运算符使用成员赋值。默认析构函数也不完成任何工作。隐式地址运算符返回调用对象的地址（即 this指针的值）。
4、修改下面类定义和声明
class nifty
{
    // data
     char personality[];
     int talents;
    // methods
     nifty();
     nifty(char * s);
     ostream & operator<<(ostream & os, nifty & n);
}

nifty:nifty()
{
     personality = NULL;
     talents = 0;
}

nifty:nifty(char * s)
{
     personality = new char [strlen(s)];
     personality = s;
     talents = 0;
}

ostream & nifty:operator<<(ostream & os, nifty & n)
{
     os << n;
}

1)
#include <iostream> 
#include <cstring> 
using namespace std; 
class nifty 
{ 
private: // optional 
    char personality[40]; // provide array size 
    int talents; 
public: // needed 
// methods 
    nifty(); 
    nifty(const char * s); 
    friend ostream & operator<<(ostream & os, const nifty & n); 
};  // note closing semicolon

nifty::nifty() 
{ 
    personality[0] = '\0'; 
    talents = 0; 
} 

nifty::nifty(const char * s) 
{ 
    strcpy(personality, s); 
    talents = 0; 
} 

ostream & operator<<(ostream & os, const nifty & n) 
{  
    os << n.personality << '\n'; 
    os << n.talent << '\n'; 
    return os;
}

2)
#include <iostream> 
#include <cstring> 
using namespace std; 
class nifty 
{ 
private: // optional 
    char * personality; // create a pointer 
    int talents; 
public: // needed 
// methods 
    nifty(); 
    nifty(const char * s); 
    nifty(const nifty & n); 
    ~nifty() { delete [] personality; } 
    nifty & operator=(const nifty & n) const; 
    friend ostream & operator<<(ostream & os, const nifty & n); 
};   // note closing semicolon 

nifty::nifty() 
{ 
    personality = NULL; 
    talents = 0; 
} 

nifty::nifty(const char * s) 
{ 
    personality = new char [strlen(s) + 1]; 
    strcpy(personality, s); 
    talents = 0; 
}

ostream & operator<<(ostream & os, const nifty & n) 
{ 
    os << n.personality << '\n'; 
    os << n.talent << '\n'; 
    return os; 
} 

5、有如下类声明
class Golfer
{
    private:
     char * fullname; // points to string containing golfer's name
     int games; // holds number of golf games played
     int * scores; // points to first element of array of golf scores
    public:
     Golfer();
     Golfer(const char * name, int g= 0);
     // creates empty dynamic array of g elements if g > 0
     Golfer(const Golfer & g);
     ~Golfer();
};
a．
1) Golfer nancy; // default constructor 
2) Golfer lulu("Little Lulu"); // Golfer(const char * name, int g) 
3) Golfer roy("Roy Hobbs", 12); // Golfer(const char * name, int g) 
4) Golfer * par = new Golfer; // default constructor 
5) Golfer next = lulu; // Golfer(const Golfer &g) 
6) Golfer hazard = "Weed Thwacker"; // Golfer(const char * name, int g) 
7) *par = nancy; // default assignment operator 
8) nancy = "Nancy Putter";// Golfer(const char * name, int g), then the default assignment operator 
类应定义一个复制数据（而不是地址）的赋值运算符。