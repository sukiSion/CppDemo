#include<iostream>
#include "move.h"

int main(int argc, char const *argv[])
{
    Move move1(2.33 , 6.66);
    Move move2(6.66 , 2.33);
    Move move3 = move1.add(move2);
    move3.showmove();
    move3.reset();
    
    return 0;
}
