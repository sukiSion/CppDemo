1、iostream 文件定义了用于管理输入和输出的类、常量和操纵符，这些对象管理用于处理I/O的流和缓冲区。该文件还创建了一些标准对象（cin、cout、cerr和clog以及对应的宽字符对象），用于处理与每个程序相连的标准输入和输出流。
2、由于计算机存储的是二进制，所以可以以文本或者二进制转换输入的121：生成3个字符，每个字符都由一个1字节的二进制码表示。要将这个值存储为int类型，则必须将这3个字符转换为121值的二进制表示。
3、在默认情况下，标准输出和标准错误都将输出发送给标准输出设备（通常为显示器）。然而，如果要求操作系统将输出重定向到文件，则标准输出将与文件（而不是显示器）相连，但标准错误仍与显示器相连。
4、ostream 类为每种C++基本类型定义了一个operator <<()函数的版本。编译器将下面的表达式：           cout << spot 解释为： cout.operator<<(spot)
5、输出方法以将返回ostream &类型的输出方法拼接。这样，通过一个对象调用方法时，将返回该对象。然后，返回对象将可以调用序列中的下一个方法。 
6、输入一个整数，以十进制、八进制、十六进制显示同时使用c++基数前缀同时每一个每种形式显示在一个宽度15个字符的字段中
#include <iostream> 
#include <iomanip> 
int main() 
{ 
    using namespace std; 
    cout << "Enter an integer: "; 
    int n; 
    cin >> n; 
    cout << setw(15) << "base ten" << setw(15) 
            << "base sixteen" << setw(15) << "base eight" << "\n"; 
    cout.setf(ios::showbase); // or cout << showbase; 
    cout << setw(15) << n << hex << setw(15) << n 
              << oct << setw(15) << n << "\n"; 
    return 0; 
} 
7、要求显示以下信息：
Enter your name: Billy Gruff
Enter your hourly wages: 12
Enter number of hours worked: 7.5
First format:
                   Billy Gruff: $     12.00:  7.5
Second format:
Billy Gruff                   : $12.00     :7.5
对应的程序为：
#include <iostream>
#include <iomanip>
int main()
{
    using namespace std;
    char name[20];
    float hourly;
    float hours;
    cout << "Enter your name: ";
    cin.get(name, 20).get();
    cout << "Enter your hourly wages: ";
    cin >> hourly;
    cout << "Enter number of hours worked: ";
    cin >> hours;
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::right, ios::adjustfield);
    // or cout << showpoint << fixed << right;
    cout << "First format:\n";
    cout << setw(30) << name << ": $" << setprecision(2)
         << setw(10) << hourly << ":" << setprecision(1)
         << setw(5) << hours << "\n";
    cout << "Second format:\n";
    cout.setf(ios::left, ios::adjustfield);
    cout << setw(30) << name << ": $" << setprecision(2)
         << setw(10) << hourly << ":" << setprecision(1)
         << setw(5) << hours << "\n";
    return 0;
}

8、有以下程序：
#include <iostream>
int main()
{
    using namespace std;
    char ch;
    int ct1 = 0;
    
    cin >> ch;
    while (ch != 'q'){
        ct1++;
        cin >> ch;
    }

    int ct2 = 0;
    cin.get(ch);
    while (ch != 'q'){
        ct2++;
        cin.get(ch);
    }
    cout << "ct1 = " << ct1 << "; ct2 = " << ct2 << endl;

    return 0;
}
当键入以下内容:
I see a q<Enter>
I see a q<Enter>
输出为:
ct1 = 5; ct2 = 9
注：>> 会抽取有效字符 ， 且使用cin.get()会把上一次使用cin >> ch读取'q'后留在输入流中的换行符读取
9、
while(cin.get() != '\n'): 会把输入缓冲流中剩余的字符全部读取（包括换行符）
cin.ignore(80 , '\n'): 当输入缓冲流中剩余的字符大于80个时，ignore()将不能正常工作。在这种情况下，它将跳过前80个字符，就是是无法将输入缓冲流清空，不建议使用，除非你能确定输入缓冲流剩余字节大小范围。