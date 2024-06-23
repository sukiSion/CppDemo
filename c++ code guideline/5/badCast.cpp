struct Base{
    virtual void f(){}
};

struct Derived: Base{};

int main(int argc, char const *argv[])
{
    Base a;
    Derived* b1 = dynamic_cast<Derived*>(&a); // 得到一个空指针
    Derived& b2 = dynamic_cast<Derived&>(a); // std::bad_cast;
    return 0;
}
