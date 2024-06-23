class Immortal{
    public:
    ~Immortal() = delete;
};

int main(int argc, char const *argv[])
{
    // 析构函数会在main函数结束时隐式调用且析构函数被设置为delete，所以编译器
    // Immortal im;
    Immortal  *pIm = new Immortal;
    // 同上,只不过这次是显式声明
    // delete pIm;
    return 0;
}
