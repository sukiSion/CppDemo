#include<string>
#include<utility>

template<class T , class... T1>
T create(T1&&... t1){
    return T(std::forward<T1>(t1)...);
}


struct MyType{
    MyType(int , double , bool){}
};

int main(int argc, char const *argv[])
{
    int five{5};
    int myFive = create<int>(five);

    int myFive2 = create<int>(5);

    int myZero = create<int>();

    MyType myType = create<MyType>(myZero , 5.5 , true);
    return 0;
}
