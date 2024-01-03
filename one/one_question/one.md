1、C++程序的模块叫函数
2、#include<iostream>作用：这将导致在最终的编译之前，使用 iostream 文件的内容替换该编译指令。
3、using namespace std作用：它使得程序可以使用 std 名称空间中的定义。
4、打印"Hello , world"并开始新的一行：std::cout << "Hello, world" << endl;
5、声明整型变量cheeses：int cheeses;
6、赋值整型变量cheeses：cheeses = 32;
7、将从键盘输入的值度如变量cheese中：cin >> cheeses;
8、打印"We have X varieties of cheeses,"，x为cheeses变量：cout << "We have " << cheeses <<  " varieties of cheeses" << endl;
9、函数信息：
int froop(double t);
调用函数 froop()时，应提供一个参数，该参数的类型为 double，而该函数将返回一个 int 值。例如，可以像下面这样使用它：int gval = froop(3.14159);
void rattle(int n);
函数 rattle()接受一个 int 参数且没有返回值。例如，可以这样使用它：rattle(37);
int prune(void);
函数 prune()不接受任何参数且返回一个 int 值。例如，可以这样使用它：int residue = prune(); 
10、当函数的返回类型为 void 时，不用在函数中使用 return。然而，如果不提供返回值，则可以使用它：return;