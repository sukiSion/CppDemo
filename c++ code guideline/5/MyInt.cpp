/**
 * 1、+运算符不对成
 * 2、val变量是公开的
 * 3、转换构造函数是隐式的
 * MyInt2.cpp解决了1、2问题
 */

struct MyInt{
    MyInt(int v): val(v){};
    MyInt operator + (const MyInt & oth) const{
        return MyInt(val + oth.val);
    }
    int val;
};

int main(int argc, char const *argv[])
{
    MyInt myFive = MyInt(2) + MyInt(3);
    MyInt myFive2 = MyInt(3) + MyInt(2);
    // 存在 MyInt和MyInt 的+
    // 隐私转换函数：5 -> MyInt(5)
    MyInt myTen = myFive + 5;
    // 由于没有 int 和 MyInt 的+运算符
    // MyInt MyTen2 = 5 + myFive;
    return 0;
}

