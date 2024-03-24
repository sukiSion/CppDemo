#include<iostream>
using std::cout;
using std::endl;

template<class T> void counts();
template<class T> void reports(const T &);

template<class T>
class HasFriend{
    private:
    T item;
    static int ct;
    public:
    HasFriend(const T & i):item(i){ct++;}
    ~HasFriend(){ct--;}
    friend void counts<T>();
    friend void reports<>(const HasFriend<T> &);
};

template<class T> int HasFriend<T>::ct = 0;

template<class T>
void counts(){
    cout << "template size: " << sizeof(HasFriend<T>) << "; ";
    cout << "template counts(): " << HasFriend<T>::ct << endl;
}

template<class T>
void reports(const T & hf){
    cout << hf.item << endl;
}



int main(int argc, char const *argv[])
{

cout << "No objects declared: ";
    counts<int>();
    HasFriend<int> hfi1(10);
    HasFriend<int> hfi2(20);
    HasFriend<double> hfdb(10.5);
    reports(hfi1);  
    reports(hfi2);  
    reports(hfdb);  
    cout << "counts<int>() output:\n";
    counts<int>();
    cout << "counts<double>() output:\n";
    counts<double>();
    return 0;
}
