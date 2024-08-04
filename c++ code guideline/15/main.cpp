#include "a.h"


/**
 * 由于a.h和b.h存在循环依赖关系，
 * 创建A类型的对象时，必须计算出类型B的对象大小
 * 创建B类型的对象时，必须计算出类型A的对象大小
 * 当成员是对象是无法计算出大小的，只有a或b之一是指针或者引用才可能确定大小
 * 可以使用前置声明解决该问题
 */
int main(int argc, char const *argv[])
{
    A myA;
    return 0;
}
