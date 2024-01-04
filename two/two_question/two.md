1、C++提供多种整型的原因：有多种整型类型，可以根据特定需求选择最适合的类型。例如，可以使用 short 来存储空格，使用long 来确保存储容量，也可以寻找可提高特定计算的速度的类型。
2、声明对应描述的变量：
a、short整数，值为80：short rbis = 80;
b、unsigned int 整数，值为42110：unsigned int q = 42110;
c、值为3000000000的整数：long long ants = 3000000000;
3、C++没有提供自动防止超出整型限制的功能，可以使用头文件 climits 来确定限制情况。
4、33L和33：常量 33L 的类型为 long，常量 33 的类型为 int。
5、char grade = 65;是否等效char grade = 'A';
这两条语句并不真正等价，虽然对于某些系统来说，它们是等效的。最重要的是，只有在使用 ASCII码的系统上，第一条语句才将得分设置为字母 A，而第二条语句还可用于使用其他编码的系统。其次，65是一个 int 常量，而‘A’是一个 char 常量。
6、使用C++找出编码为88的字符：
(1)char c = 88;
(2)char(88);
(3)(char)88;
(4) static_cast<char>(88);
7、将long类型赋值float变量会导致舍入误差，将long值赋给double变量呢？将long long值赋给double变量呢？
这个问题的答案取决于这两个类型的长度。如果 long 为 4 个字节，则没有损失（float也是4字节）。因为最大的 long值将是 20 亿，即有 10 位数。由于 double 提供了至少 13 位有效数字，因而不需要进行任何舍入。long long类型可提供 19 位有效数字，超过了 double 保证的 13 位有效数字。
8、表达式结果：
(1)8 * 9 + 2 = 74;
(2)6 * 3 / 4 = 4;
(3)3 / 4 * 6 = 0;
(4)6.0 * 3 / 4 = 4.5;
(5)15 % 4 = 3;
9、两个double类型整数部分相加：
(1)int pos = int(x1) + int(x2);
(2)int pos = (int)x1 = (int)x2;
两个double类型相加转换为整型：
(1)int pos = (int)(x1 + x2);
(2)int pos = int(x1 + x2);
10、声明下列语句变量类型：
(1)auto cars = 15; => int
(2)auto iou = 150.37f; => float
(3)auto level = 'B'; => chat
(4)auto crat = U'\U00002155'; => char32_t;
(5)auto fract = 8.25f/2.5; => double
