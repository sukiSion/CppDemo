#include <iostream>
#include <string>
#include <utility>

class Cpmv{
    public:
    struct Info{
        std::string qcode;
        std::string zcode;
    };
    private:
    Info * pi;
    public:
    Cpmv(): pi(nullptr){}
    Cpmv(std::string q , std::string z);
    Cpmv(const Cpmv & cp);
    Cpmv(Cpmv && mv);
    ~Cpmv(){
        delete pi;
    }
    Cpmv & operator=(const Cpmv & cp);
    Cpmv & operator=(Cpmv && mv);
    Cpmv operator+(const Cpmv &obj) const;
    void Display() const;   
};

Cpmv::Cpmv(std::string q , std::string z){
    pi = new Info;
    pi->qcode = q;
    pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv & cp){
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
}

Cpmv::Cpmv(Cpmv && mv){
    pi = mv.pi;
    mv.pi = nullptr;
}

Cpmv & Cpmv::operator=(const Cpmv & cp){
    if(&cp == this){
        return *this;
    }
    delete pi;
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
    return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv){
    if(&mv == this){
        return *this;
    }
    pi = mv.pi;
    mv.pi = nullptr;
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv &obj) const
{
    return Cpmv(pi->qcode.append(" ").append(obj.pi->qcode), pi->zcode.append(" ").append(pi->zcode));
}

void Cpmv::Display() const
{
    if (pi)
    {
        std::cout << "The qcode is " << pi->qcode << std::endl;
        std::cout << "The zcode is " << pi->zcode << std::endl;
    }
    else
    {
        std::cout << "Cpmv::pi pointer is nullptr" << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    using std::cout;
    Cpmv temp1;
    cout << "temp1:\n";
    temp1.Display();

    Cpmv temp2("mzzdx", "god");
    cout << "temp2:\n";
    temp2.Display();

    cout << "Cpmv temp3(temp2): " << std::endl;
    Cpmv temp3(temp2);
    cout << "temp3:\n";
    temp3.Display();

    cout << "temp4 = temp2:\n";
    Cpmv temp4;
    temp4 = temp2;
    cout << "temp4:\n";
    temp4.Display();
    cout << "temp2:\n";
    temp2.Display();

    cout << "temp5 = move(temp2):\n";
    Cpmv temp5;
    temp5 = std::move(temp2);
    cout << "temp5:\n";
    temp5.Display();
    cout << "temp2:\n";
    temp2.Display();

    cout << "temp6 = temp3 + temp4:\n";
    Cpmv temp6 = temp3 + temp4;
    cout << "temp6:\n";
    temp6.Display();

    return 0;
}
