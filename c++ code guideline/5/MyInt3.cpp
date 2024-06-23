// 由于隐式转换失效,所以需要额外两个友元:一个接受int类型在左边的函数,一个接受int类型在右边的函数
class MyInt3{
    public:
    MyInt3(int v): val(v){};
    friend MyInt3 operator + (const MyInt3 & fir , const MyInt3 & sec) {
        return MyInt3(fir.val + sec.val);
    }
    friend MyInt3 operator + (int fir , const MyInt3 & sec) {
        return MyInt3(fir + sec.val);
    }
    friend MyInt3 operator + (const MyInt3 & fir ,int sec) {
        return MyInt3(fir.val + sec);
    }
    private:
    int val;
};

int main(int argc, char const *argv[])
{
    MyInt3 myFive = MyInt3(2) + MyInt3(3);
    MyInt3 myFive2 = MyInt3(3) + MyInt3(2);
    MyInt3 myTen = myFive + 5;
    MyInt3 MyTen2 = 5 + myFive;
    return 0;
}
