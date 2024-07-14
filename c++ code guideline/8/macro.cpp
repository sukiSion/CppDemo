#include<stdio.h>
#define max(a , b) ((a) > (b)) ? (a) : (b)

int main(int argc, char const *argv[])
{
    int a = 1 , b = 2;
    printf("\nmax(a , b): %d\n" , max(a , b));
    printf("a = %d , b = %d\n" , a , b);
    // 宏替换得：((++a) > (++b)) ? (++a) : (++b)
    // 由于++b > ++a，所以得到++b，即++b了两次
    // 若++a > ++b同理
    printf("\nmax(++a , ++b): %d\n" , max(++a , ++b));
    printf("a = %d , b = %d\n" , a , b);
    return 0;
}
