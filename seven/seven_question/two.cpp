#include<iostream>
using namespace std;
struct CandyBar
{
    const char * brand;
    double weight;
    int heat;
};

void show(const CandyBar & candyBar);
void show(const CandyBar & candyBar){
   cout << candyBar.brand << " " << candyBar.weight << " " << candyBar.heat << endl;
}

void input(CandyBar & candyBar , const char ch[] = "Millennium Munch" , double weight = 2.85 , int heat = 350);
void input(CandyBar & candyBar , const char ch[], double weight , int heat){
    candyBar.brand = ch;
    candyBar.weight = weight;
    candyBar.heat = heat;
}


int main(int argc, char const *argv[])
{
    CandyBar candyBar;
    input(candyBar);
    show(candyBar);
    return 0;
}
