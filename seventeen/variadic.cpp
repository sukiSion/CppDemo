#include<iostream>
#include<string>

void show_list3(){}

template<class T , class... Args>
void show_list3(T value , Args... args){
    std::cout << value << ", ";
    show_list3(args...);
}

int main(int argc, char const *argv[])
{
    int n = 14;
    double x = 2.71828;
    std::string mr = "Mr. String objects!";
    show_list3(n , x);
    show_list3(x * x , '!' , 7 , mr);
    return 0;
}
