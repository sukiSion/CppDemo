#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>

int main(int argc, char const *argv[])
{
    using namespace std;
    auto outint = [](int n){
        cout << n << " ";
    };
    int vals[]{
        50 , 100 , 90 , 180 , 60 , 210 , 415 , 88 , 188 , 201
    };
    list<int> yadayada(vals , vals + 10);
    list<int> etcetera(vals , vals + 10);
    cout << "Original lists:" << endl;
    for_each(yadayada.begin() , yadayada.end() , outint);
    cout << endl;
    for_each(etcetera.begin() , etcetera.end() , outint);
    cout << endl;
    yadayada.remove_if([](int x ){
        return x > 100;
    });
    etcetera.remove_if([](int x ){
        return x > 200;
    });
    cout << "Trimmed lists:" << endl;
    for_each(yadayada.begin() , yadayada.end() , outint);
    cout << endl;
    for_each(etcetera.begin() , etcetera.end() , outint);
    cout << endl;
    return 0;
}
