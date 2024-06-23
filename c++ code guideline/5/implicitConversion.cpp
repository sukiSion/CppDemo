#include<iostream>
#include<string>

struct MyHouse{
    MyHouse() = default;
    explicit MyHouse(const std::string& fam):family(fam){}
    operator bool(){
        return not family.empty();
    }
    // 若声明了explicit，运算将不再可能，但依旧可以用于逻辑表达式
    // explicit operator bool(){
    //     return not family.empty();
    // }
    std::string family = "";
};

int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha << '\n';

    MyHouse firstHouse;
    if(not firstHouse){
        std::cout << "firstHouse is not sold.\n";
    }
    MyHouse secondHouse("grimm");
    if(secondHouse){
        std::cout << "Grimm bought secondHouse.\n";
    }
    std::cout << '\n';
    // 由于bool运算符没有声明explicit
    // firstHoust为false，提升为0
    // secondHouse为true，提升为1
    int myNewHouse = firstHouse + secondHouse; 
    int myNewHouse2 = (20 * firstHouse - 10 * secondHouse);
    std::cout << "myNewHouse: " << myNewHouse << std::endl;
    std::cout << "myNewHouse2: " << myNewHouse2 << std::endl;
    std::cout << '\n';
    return 0;
}
