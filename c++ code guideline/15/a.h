#ifndef LIBRARY_A_H
#define LIBRARY_A_H
// #include "b.h"

// 由于循环依赖导致编译失败
// class A{
//     B b;
// };

// 修正
class B;

class A{
    B* b;
    B& b2 = *b;
};


#endif