#include "stock.h"
static const int STKS = 4;
int main(int argc, char const *argv[])
{
    Stock stocks[STKS]{
        {"NanoSmart" , 12 , 20.0},
        {"Boffo Objects" , 200 , 2.0},
        {"Monolithic Obelisks" , 130 , 3.25},
        {"Fleep Enterprises" , 60 , 6.5}
    };
    std::cout << "Stock holdings:\n";
    int st;
    for(st = 0 ; st < STKS ; st++){
        std::cout << stocks[st];
    }
    const Stock * top = &stocks[0];
    for(st = 1 ; st < STKS ; st++){
        top = &((/*  */*top).topval(stocks[st]));
    }
    std::cout << "\nMost valuable holding:\n";
    std::cout << *top;
    return 0;
}
