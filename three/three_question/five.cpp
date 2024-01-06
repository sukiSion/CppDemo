#include<iostream>
#include<string>
using namespace std;


struct CandyBar
{
   string brand;
   float weight;
   int calories;
};


int main(int argc, char const *argv[])
{
    CandyBar snack{
        "Mocha Munch",
        2.3,
        350
    };
    cout << "snack: brand = " << snack.brand << ", weight = " << snack.weight << ", calories = " << snack.calories << endl;
    return 0;
}
