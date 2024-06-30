/**
 * 由于Mother和Son由于shared_ptr互相引用，导致引用计数总是大于0导致析构函数不会被调用
 * 但是Daughter使用weak_ptr，当其离开作用域后引用计数变为0，析构函数被调用从而被删除
 */
#include<iostream>
#include<memory>

struct Son;
struct Daugther;

struct Mother{
    ~Mother(){
        std::cout << "Mother gone" << '\n';
    }
    void setSon(const std::shared_ptr<Son> s){
        mySon = s;
    }
    void setDaugther(const std::shared_ptr<Daugther> d){
        myDaugther = d;
    }

    std::shared_ptr<Son> mySon;
    std::weak_ptr<Daugther> myDaugther;
};

struct Son{
    explicit Son(std::shared_ptr<Mother> m): myMother(m){}
    ~Son(){
        std::cout << "Son gone" << '\n';
    }
    std::shared_ptr<Mother> myMother;
};

struct Daugther{
    explicit Daugther(std::shared_ptr<Mother> m): myMother(m){}
    ~Daugther(){
        std::cout << "Daugther gone" << '\n';
    }
    std::shared_ptr<Mother> myMother;
};

int main(int argc, char const *argv[])
{
    std::shared_ptr<Mother> m = std::make_shared<Mother>();
    std::shared_ptr<Son> s = std::make_shared<Son>(m);
    std::shared_ptr<Daugther> d = std::make_shared<Daugther>(m);

    m->setSon(s);
    m->setDaugther(d);

    return 0;
}
