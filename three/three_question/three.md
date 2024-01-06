1、声明数据：
(1)30个char组成的数组：char actor[30];
(2)100个short组成的数组：short betsie[100];
(3)13个float组成的数组：float chuck[13];
(4)64个long double组成的数组：long double dipsea[64];
2、使用array：
(1)30个char组成的array：array<char , 30> actor;
(2)100个short组成的array：array<short , 100> betsie;
(3)13个float组成的array：array<float , 13> chuck;
(4)64个long double组成的array：array<long double , 64> dipsea;
3、声明一个包含5个元素的int数组，并将它初始化为前5个正奇数：int oddly[5] {1，3，5，7，9};
4、编写一条语句，将问题3中数组的一个元素和最后一个元素的和赋值给变量event：int event = oddly[0] + oddly[4];
5、编写一条语句，显示float数组ideas中的第2个元素的值：cout << ideas[1] << endl;
6、声明一个char的数组，并将其初始化为字符串"cheeseburger"：char lunch[13] = "cheeseburger"; or char lunch[] = "cheeseburger";
7、声明一个string对象，并将其初始化为字符串"Waldorf Salad"：string lunch = "Waldorf Salad"; 
8、设计一个描述鱼的结构声明。结构中应包括品种、重量（整数，单位为盎司）和长度（英寸，包括小数）:
struct Fish{
    char kind[20]; 
    int weight; 
    float length; 
}
9、初始化结构：
fish petes = { 
    "trout", 
    12, 
    26.25 
 }; 
 10、enum{
    No,
    Yes,
    Maybe
 }
11、声明一个指向double ted变量的指针：double * pd = &ted;
使用该指针显示double ted的值：cout << *pd << endl;
12、声明一个执行10个float元素数组treacle第一个元素的指针，使用该指针显示数组的第一个元素和最后一个元素：
float * pf = treacle;
cout << pf[0] << " " << pf[9] << endl;
13、编写一段代码，要求用户输入一个正整数，然后创建一个动态的int数组，其中包含的元素数目等于用户输入的值。 
unsigned int size; 
cout << "Enter a positive integer: "; 
cin >> size; 
int * dyn = new int [size]; 
// 使用new
int * dyn = new int [size];
// 使用vector
vector<int> dv(size);
14、" cout << (int *)"Home of the jolly bytes" "是否有效，将打印什么结果
是的，它是有效的。表达式“home of the jolly bytes”是一个字符串常量，因此，它将判定为字符串开始的地址。cout 对象将 char 地址解释为打印字符串，但类型转换(int *)将地址转换为 int 指针，然后作为地址被打印。总之，该语句打印字符串的地址，只要 int 类型足够宽，能够存储该地址。
15、给上面的结构动态分配内存，在读取该结构成员的值：
struct fish 
{ 
    char kind[20]; 
    int weight; 
    float length; 
}; 
fish * pole = new fish; 
cout << "Enter kind of fish: "; 
cin >> pole->kind; 
16、相比于使用cin.getline(address , 80); ，使用cin >> address 有什么影响：使用 cin >>address 将使得程序跳过空白，直到找到非空白字符为止。然后它将读取字符，直到再次遇到空白为止。因此，它将跳过数字输入后的换行符，从而避免这种问题。另一方面，它只读取一个单词，而不是整行。
17、声明两个分别包含10个string对象的vector对象和array对象。指出所需要的头文件，使用const来指定要包含的string对象数
#include <string>
#include <vector> 
#include <array> 
const int Str_num {10}; // or = 10 
... 
std::vector<std::string> vstr(Str_num); 
std::array<std::string, Str_num> astr; 