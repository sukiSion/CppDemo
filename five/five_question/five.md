1、if-if和if-else if 比较好处是：1、当判断一个字符时，使用if-if一定需要进行两次判断，而if-else if则最多需要两次判断，所以if-else if效率会更高，这只是一适用情况，因为基本上判断一个字符为对应类型的字符后，其他类型就可以排除了。
2、++char;和char++的区别：前面是再ASCII码中的下一个字符，也就是打印++char还是打印字符，但是char+1会向上转型成更高一级的类型，也就是1所代表的int整型，所以打印的是数字
3、创建对应条件的逻辑表达式：
(1) weight大于或等于115，但小于125：weight >= 115 && weight < 125
(2) ch为q或Q：ch == 'q' || ch == 'Q'
(3) x为偶数，但不是26：x % 2 == 0 && x != 26
(4) x为偶数，但不是26的倍数：x % 2 == 0 && x % 26 != 0
(5) donation为1000-2000或guest为1：(donation >= 1000 && donation <= 2000 ) || guest == 1
(6) ch是小写字母或者大写字符：(ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')
4、在c++中，!!x可能不等于x
5、(x >= 0) ? x : -x // (x < 0) ? -x : x
6、使用字符相比使用整数的好处：在输入时，如果使用整数标签，且用户输入了非整数（如 q），则程序将因为整数输入不能处理字符而挂起。但是，如果使用字符标签，而用户输入了整数（如 5），则字符输入将 5 作为字符处理。