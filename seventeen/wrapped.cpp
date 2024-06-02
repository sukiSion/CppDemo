#include<functional>
#include<iostream>

template<class T , class F>
T use_f(T v , F f){
    static int count = 0;
    count++;
    std::cout << "use_f count = " << count << ", &count = " << &count << std::endl;
    return f(v);
}

class Fp{
    private:
    double z_;
    public:
    Fp(double z = 1.0): z_(z){}
    double operator()(double p){
        return z_ * p;
    }
};

class Fq{
    private:
    double z_;
    public:
    Fq(double z = 1.0): z_(z){}
    double operator()(double q){
        return z_ + q;
    }
};


double dub(double x){
    return 2.0 * x;
}

double square(double x){
    return x * x;
}

int main(int argc, char const *argv[])
{
    using namespace std;

    double y = 1.21;
    function<double(double)> ef1 = dub;
    function<double(double)> ef2 = square;
    function<double(double)> ef3 = Fp(5.0);
    function<double(double)> ef4 = Fq(5.0);
    function<double(double)> ef5 = [](double u){return u * u;};
    function<double(double)> ef6 = [](double u){return u + u / 2.0;};

    cout << "Function pointer dub:\n";
    cout << " " << use_f(y , ef1) << endl;
    cout << "Function pointer square:\n";
    cout << " " << use_f(y , ef2) << endl;
    cout << "Function Object Fp:\n";
    cout << " " << use_f(y , ef3) << endl;
    cout << "Function Object Fq:\n";
    cout << " " << use_f(y , ef4) << endl;
    cout << "Lambda expression 1:\n";
    cout << " " << use_f(y , ef5) << endl;
    cout << "Lambda expression 2:\n";
    cout << " " << use_f(y , ef6) << endl;
    return 0;
}
