#include<functional>
#include<iostream>
#include<string>

auto makeLambda(){
    const std::string val = "on stack created";
    return [&val]{return val;};
}

int main(int argc, char const *argv[])
{
    auto bad = makeLambda();
    std::cout << bad();
    return 0;
}
