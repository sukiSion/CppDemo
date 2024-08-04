#include<iostream>
#include<string>

int main(int argc, char const *argv[])
{
    std::string text{"The text is not too long."};
    std::cout << "text.size(): " << text.size() << '\n';
    std::cout << text << '\n';
    text += " And can still grow!";
    std::cout << "text.size(): " << text.size() << '\n';
    std::cout << text << '\n';
    return 0;
}

