#include<iostream>
using std::cout;
using std::endl;

template<class T>
class ManyFriend{
    private:
    T item;
    public:
    ManyFriend(const T & i): item(i){}
    template<class C , class D>
    friend void show(const C & c, const D & d);
};

template<class C , class D>
void show(const C & c, const D & d){
    cout << c.item << ", " << d.item << endl;
}

int main(int argc, char const *argv[])
{
     ManyFriend<int> hfi1(10);
    ManyFriend<int> hfi2(20);
    ManyFriend<double> hfdb(10.5);
    cout << "hfi1, hfi2: ";
    show(hfi1, hfi2);
    cout << "hfdb, hfi2: ";
    show(hfdb, hfi2);
    return 0;
}
