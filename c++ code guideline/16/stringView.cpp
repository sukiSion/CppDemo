#include<cassert>
#include<iostream>
#include<string_view>
#include<string>

void* operator new(std::size_t count){
    std::cout << " " << count << " bytes" << '\n';
    return malloc(count);
}

void getString(const std::string& str){}
void getStringView(std::string_view strView){}


int main(int argc, char const *argv[])
{
    std::cout << '\n';
    std::cout << "std::string" << '\n';
    std::string large = "0123456789-123456789-123456789-123456789"; // 内存分配
    std::string substr = large.substr(10); // 内存分配
    std::cout << '\n';

    std::cout << "std::string_view" << '\n';
    // 由于stringView不拥有该字符序列，所以没有进行内存分配
    std::string_view largeStringView{large.c_str() , large.size()};
    largeStringView.remove_prefix(10);
    std::cout << '\n';

    std::cout << "getString" << '\n';
    getString(large);
    getString("0123456789-123456789-123456789-123456789"); // 内存分配
    const char message[] = "0123456789-123456789-123456789-123456789";
    getString(message); // 内存分配
    std::cout << '\n';

    std::cout << "getStringView" << '\n';
    getStringView(large);
    getStringView("0123456789-123456789-123456789-123456789"); 
    getStringView(message); 
    std::cout << '\n';

    return 0;
}
