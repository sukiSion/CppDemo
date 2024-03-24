#include<iostream>
using std::cout;
using std::endl;
template<class T>
class beta{
    private:
    template<class V>
    class hold{
        private:
        V val;
        public:
        hold(V v = nullptr): val(v){}
        void show() const {
            cout << val << endl;
        }
        V Value() const{return val;}
    };
    hold<T> q;
    hold<int> n;
    public:
    beta(T t , int i):q(t) , n(i){}
    template<class U>
    U blad(U u , T t){
        return (n.Value() + q.Value()) * u / t;
    }
    void Show() const{
        q.show() ; 
        n.show();
    }
};

int main(int argc, char const *argv[])
{
    beta<double> guy(3.5 , 3);
    cout << "T was set ti double" << endl;
    guy.Show();
    cout << "V was set to T, which is double, then V was set to int" << endl;
    cout << guy.blad(10 , 2.3) << endl;
    cout << "U was set to int" << endl;
    cout << guy.blad(10.0 , 2.3) << endl;
    cout << "U was set to double" << endl;
    cout << "Done" << endl;
    return 0;
}
