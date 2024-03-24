#include "work0.h"
#include<iostream>
static const int LIM = 4;
int main(int argc, char const *argv[])
{
    Waiter bob("Bob Apple" , 314L , 5);
    Singer bev("Beverly Hills" , 522L , 3);
    Waiter t_temp;
    Singer s_temp;
    Worker * pw[LIM] = {&bob , &bev , &t_temp , &s_temp};
    int i;
    for(i = 2 ; i < LIM ; i++){
        pw[i]->Set();
    }
    for(i = 0 ; i < LIM ; i++){
        pw[i]->Show();
        std::cout << std::endl;
    }
    return 0;
}
