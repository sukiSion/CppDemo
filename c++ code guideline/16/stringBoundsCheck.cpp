#include<iostream>
#include<string>
#include<stdexcept>

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    std::string str("1123456789");
    str.at(0) = '0';
    std::cout << str << '\n';

    std::cout << "str.size(): " << str.size() << '\n';
    std::cout << "str.capacity(): " << str.capacity() << '\n';

    try{
        str.at(12) = 'x';
    }catch(const std::out_of_range& exc){
        std::cout << exc.what() << '\n';
    }
    std::cout << '\n';

    return 0;
}
