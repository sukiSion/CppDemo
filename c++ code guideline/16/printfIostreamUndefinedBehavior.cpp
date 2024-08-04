#include<cstdio>
#include<iostream>

int main(int argc, char const *argv[])
{
    printf("\n");

    printf("2011: %d\n" , 2011);
    printf("3.1416: %d\n" , 3.1416);
    printf("\"2011\": %s\n" , "2011");
    // 段错误
    // printf("%s\n" , 2011); 

    std::cout << '\n';
    std::cout << "2011: " << 2011 << '\n';
    std::cout << "3.1416: " << 3.1416 << '\n';
    std::cout << "\"2011\": " << "2011" << '\n';

    std::cout << '\n';
    return 0;
}
