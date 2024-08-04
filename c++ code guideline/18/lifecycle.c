#include<stdio.h>


/**
 * 可以替换为RAII，在构造函数中初始化资源，在析构函数中释放资源，并使用{}来控制声明周期
 */
void initDevide(const char* mess){
    printf("\n\nINIT: %s\n" , mess);
}

void work(const char* mess){
    printf("WORKING: %s" , mess);
}

void shutDownDevice(const char* mess){
    printf("\nSHUT DOWN: %s\n\n" , mess);
}

int main(int argc, char const *argv[])
{
    initDevide("DEVICE 1");
    work("DEVICE 1");
    {
        initDevide("DEVICE 2");
        work("DEVICE 2");
        shutDownDevice("DEVICE 2");
    }
    work("DEVICE 1");
    shutDownDevice("DEVICE 1");
    return 0;
}
