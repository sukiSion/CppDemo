#include<iostream>
#include<memory>
#include<string>

struct Base{
    public:
    Base() = default;
    virtual ~Base() = default;
    virtual std::unique_ptr<Base> clone(){
        return std::unique_ptr<Base>{
            new Base(*this)
        };
    }
    virtual std::string getName() const {
        return "Base";
    }
    protected:
    Base(const Base&) = default;
    Base& operator = (const Base&) = default;
};

struct Derived: public Base{
    Derived() = default;
    std::unique_ptr<Base> clone() override{
        return std::unique_ptr<Derived>{
            new Derived(*this)
        };
    }
    std::string getName() const override{
        return "Derived";
    }
    protected:
    Derived(const Derived&) = default;
    Derived& operator = (const Derived&) = default;
};

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    auto base1 = std::make_unique<Base>();
    auto base2 = base1->clone();
    std::cout << "base1->getName(): " << base1->getName() << std::endl; 
    std::cout << "base2->getName(): " << base2->getName() << std::endl; 

    auto derived1 = std::make_unique<Derived>();
    auto derived2 = derived1->clone();
    std::cout << "derived1->getName(): " << derived1->getName() << std::endl; 
    std::cout << "derived2->getName(): " << derived2->getName() << std::endl; 
    std::cout << '\n';
    return 0;
}
